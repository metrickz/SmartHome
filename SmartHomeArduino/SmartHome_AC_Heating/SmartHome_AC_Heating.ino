

#define ZERO_CROSS      2   // Input 
#define FIRE_AC_HEATING   3  // Output

int inputByte;
int dimValue = 255;

void setup() {
  Serial.begin(115200);   // Initialize serial port for communication with host pc
  
  pinMode(FIRE_AC_HEATING, OUTPUT); 
  pinMode(ZERO_CROSS,INPUT);
}

void loop() {
  if (Serial.available() > 0) {
    inputByte = Serial.read();
    dimValue = 255-inputByte/4; // Limit Heating element

  }

  if(digitalRead(ZERO_CROSS) == HIGH){
      int dimtime = (2*dimValue+1);  // 39.0625 => 10.000 Microseconds / 255    
      delayMicroseconds(dimtime);     // Off cycle
      digitalWrite(FIRE_AC_HEATING, HIGH);   // triac firing
      delayMicroseconds(10);
      digitalWrite(FIRE_AC_HEATING, LOW);
  }
}
