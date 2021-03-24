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
#define ALTITUDE        700




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


void setup() {
  Serial.begin(115200);   // Initialize serial port for communication with host pc
  Serial1.begin(115200);  // Initialize serial port for communication with dimmer arduino

  Serial.println("SETUP");
  
  Motor.setSpeed(5);
  dht.begin();
  Serial.println("DHT Sensor started");
  BMP.init(BMP180_STANDARD);
  Serial.println("BMP Sensor started");
  Serial.println("---- Sensors initialized");


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
  Serial.print("Timer interrupt set...");
}


void loop() {

  // Read  sensor data
  brightness = analogRead(BRIGHTNESS_IN);
  temperature = dht.readTemperature(); 
  humidty = dht.readHumidity();
  pressure = BMP.readReducedPress(665); 

  

  // Receive serial data
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
    Serial.print("<9:"+String(steps)+">");     // Shutters
  }

  if(shuttersUp == true && shutterIsOpened == false){
    Motor.step(-1);
    steps--;
    Serial.print("<9:"+String(steps)+">");     // Shutters
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

ISR(TIMER3_COMPA_vect){    
  // Send sensor data to Host
  Serial.print("<5:"+String(temperature)+">");
  Serial.print("<6:"+String(humidty)+">");
  Serial.print("<7:"+String(brightness)+">");
  Serial.print("<8:"+String(pressure)+">");
}

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


void parseData() {      
    char * strtokIndx; 
    
    strtokIndx = strtok(receivedChars, ":"); 
    device = atoi(strtokIndx);   
      
    strtokIndx = strtok(NULL, ":");
    value = atof(strtokIndx);     
}


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
          //Motor.step(2048);
        }else if(value==1){
          shuttersDown = true;
          shuttersUp = false;
          //Motor.step(-2048);
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
        
    }
}
