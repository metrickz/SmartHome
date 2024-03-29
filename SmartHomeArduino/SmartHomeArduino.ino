#include <MyBMP180.h>
#include <ServoTimer2.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "DHT.h"
#include <Stepper.h>



// SETUP PINS
#define SERVO_SHUTTERS  8   //Output
#define MOTOR_PIN_1     22  // Output
#define MOTOR_PIN_2     23  // Output
#define MOTOR_PIN_3     24  // Output
#define MOTOR_PIN_4     25  // Output
#define DHT11_IN        26  // Input
#define BRIGHTNESS_IN   A0  // Input


DHT         dht(DHT11_IN, DHT11);
Stepper     Motor(2048, MOTOR_PIN_1,MOTOR_PIN_3,MOTOR_PIN_2,MOTOR_PIN_4);
ServoTimer2 servo_tiltWindow;
MyBMP180    BMP(0x77);

int device, value;
int brightness;
float temperature;
float humidty;
float airpressure;
const byte numChars = 32;
char receivedChars[numChars];      
boolean newData = false;
boolean shuttersDown = false;
boolean shuttersUp = false;
boolean shutterIsClosed = false; //Software sensor
boolean shutterIsOpened = true;
int steps = 0;
int dimming = 0;
int pressure = 0;
int altitude = 700;


// PID variables
float setpoint = 0;
float PID_error = 0;
float previous_error = 0;
float elapsedTime, Time, timePrev;
float PID_value = 0;

//PID factors
int kp = 30;   int ki = 0.2;   int kd = 1.7;

// PID final values
int PID_p = 0;    int PID_i = 0;    int PID_d = 0;


void setup() {
  Serial.begin(115200);   // Initialize serial port for communication with host pc
  Serial1.begin(115200);  // Initialize serial port for communication with dimmer1 arduino
  Serial2.begin(115200);  // Initialize serial port for communication with dimmer2 arduino
  
  Motor.setSpeed(5);
  dht.begin();
  BMP.init(BMP180_STANDARD);



  // Timer 3 (16Bit)
  cli();
  TCCR3A = 0; // set TCCRXA register to 0
  TCCR3B = 0; // set TCCRXB register to 0
  TCNT3  = 0; // reset counter value
  OCR3A = 0xB71A; //Every 3 seconds interrupt => ((16MHz * 3s)/1024)-1
  TCCR3B |= (1 << WGM32); // enable timer1 CTC mode
  TIMSK3 |= (1 << OCIE3A); // enable timer1 compare interrupt
  TCCR3B |= (1 << CS12) | (1 << CS10);    // Prescaler 1024
  sei();
}


void loop() {

  /*---------------------------------------------------------------*/
  // Read  sensor data
  /*---------------------------------------------------------------*/
  brightness = analogRead(BRIGHTNESS_IN);
  temperature = dht.readTemperature(); 
  humidty = dht.readHumidity();
  pressure = BMP.readReducedPress(altitude);


  /*---------------------------------------------------------------*/
  // PID controller
  /*---------------------------------------------------------------*/

  if(setpoint > 22){
    // Calculate error
    PID_error = setpoint - temperature;
  
    // Calculate P value
    PID_p = kp * PID_error;
  
    // Calculate I value withing a specific range
    if(-1 < PID_error < 1)
    {
      PID_i = PID_i + (ki * PID_error);
    }
  
    // Calculate D value
    timePrev = Time;                            
    Time = millis();                            
    elapsedTime = (Time - timePrev) / 1000; 
    
    PID_d = kd*((PID_error - previous_error)/elapsedTime);
    
    // Sum of values
    PID_value = PID_p + PID_i + PID_d;
  
    // range has to be within 1 byte
    if(PID_value < 0){
      PID_value = 0;  
    } 
    if(PID_value > 255){
        PID_value = 255;  
    }     
    Serial2.write((int)PID_value);
    previous_error = PID_error; 
  }else{
    Serial2.write(0);
  }
  
  
  

  /*---------------------------------------------------------------*/
  // Receive serial data from host
  /*---------------------------------------------------------------*/
  if (Serial.available() > 0) {
    recv_serial();
    if (newData == true) {
        parseData();
        processData();
        newData = false;
    }
  }


  // Control Shutters
  if(shuttersDown == true && shutterIsClosed == false){
    Motor.step(1);
    steps++;
    Serial.print("<9:"+String(steps)+">");     
  }

  if(shuttersUp == true && shutterIsOpened == false){
    Motor.step(-1);
    steps--;
    Serial.print("<9:"+String(steps)+">");     
  }

  // Software Limit Switch for Shutters
  if(steps < 2048){
    shutterIsClosed = false;
  }else if(steps == 2048){
    shutterIsClosed = true;
  }
  if(steps > 0){
    shutterIsOpened = false;
  }else if(steps == 0){
    shutterIsOpened = true;
  }
}


  /*---------------------------------------------------------------*/
  // Send sensor data to host every interrupt
  /*---------------------------------------------------------------*/

ISR(TIMER3_COMPA_vect){    
  // Send sensor data to Host
  Serial.print("<5:"+String(temperature)+">");
  Serial.print("<6:"+String(humidty)+">");
  Serial.print("<7:"+String(brightness)+">");
  Serial.print("<8:"+String(pressure)+">");

  Serial.print("<10:"+String(PID_value)+">");
  Serial.print("<11:"+String(setpoint)+">");
  Serial.print("<12:"+String(PID_error)+">");
}


  /*---------------------------------------------------------------*/
  // Receive serial data and listen for valid data
  /*---------------------------------------------------------------*/
void recv_serial() {
    static boolean recvInProgress = false;
    static byte index = 0;
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != '>') {
                receivedChars[index] = rc;
                index++;
                if (index >= numChars) {
                    index = numChars - 1;
                }
            }
            else {
                receivedChars[index] = '\0'; // terminate the string
                recvInProgress = false;
                index = 0;
                newData = true;
            }
        }
        else if (rc == '<') {
            recvInProgress = true;
        }
    }
}

  /*---------------------------------------------------------------*/
  // Parse / Split valid data package
  /*---------------------------------------------------------------*/
void parseData() {      
    char * strtokIndx; 
    
    strtokIndx = strtok(receivedChars, ":"); 
    device = atoi(strtokIndx);   
      
    strtokIndx = strtok(NULL, ":");
    value = atof(strtokIndx);     
}


  /*---------------------------------------------------------------*/
  // Control actuators
  /*---------------------------------------------------------------*/
void processData() {
    switch(device){

      // Dim Light
      case 1:
          Serial1.write(value);
        break;

      // Shutters
      case 2:
        if(value==0){
          shuttersUp = true;
          shuttersDown = false;
        }else if(value==1){
          shuttersDown = true;
          shuttersUp = false;
        }
        break;

      // Tilt Window
      case 3:
        if(value==0){
          servo_tiltWindow.attach(SERVO_SHUTTERS);
          servo_tiltWindow.write(750);
          delay(300);
          servo_tiltWindow.detach();
        }else if(value==1){
          servo_tiltWindow.attach(SERVO_SHUTTERS);
          servo_tiltWindow.write(2250);
          delay(300);
          servo_tiltWindow.detach();
        }
        break;

        // Set Temperature
      case 4:
        int mapped_val = map(value, 0, 255, 22, 28);
        setpoint = mapped_val;
        
    }
}
