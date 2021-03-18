#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Stepper.h>
#include "DHT.h"

DHT dht(2, DHT11);
Stepper Motor(2048, 4,6,5,7);

void setup() {
  
  Serial.begin(115200); // Initialize serial port to send and receive at 9600 baud
  
  pinMode(3, OUTPUT); 
    
  dht.begin();
  Motor.setSpeed(5);
  
  cli();
  
  // reset timer 1
  TCCR1A = 0; // set TCCRXA register to 0
  TCCR1B = 0; // set TCCRXB register to 0
  TCNT1  = 0; // reset counter value

  TCCR1B |= (1 << WGM12); // enable timer1 CTC mode
  TIMSK1 |= (1 << OCIE1A); // enable timer1 compare interrupt

  OCR1A = 0xB71A; //Every 3 seconds interrupt => ((16MHz * 3s)/1024)-1

  TCCR1B |= (1 << CS12) | (1 << CS10);    // Prescaler 1024
  sei();

  
}



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


void loop() {
  
  // Read  sensor data
  brightness = analogRead(A0);
  temperature = dht.readTemperature(); 
  humidty = dht.readHumidity();

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

ISR(TIMER1_COMPA_vect){    
  // Send sensor data to Host
  Serial.print("<5:"+String(temperature)+">");
  Serial.print("<6:"+String(humidty)+">");
  Serial.print("<7:"+String(brightness)+">");
  Serial.print("<8:481>"); 
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
      case 1:
        if(value==0){
          digitalWrite(3, LOW);
        }else if(value==255){
          digitalWrite(3, HIGH);
        }else{
          analogWrite(3,value);
        }
        break;
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
        
    }
}