

#define ZERO_CROSS      2   // Input 
#define FIRE_AC_LIGHT        3  // Output

int inputByte;
int dimValue;

void setup() {
  Serial.begin(115200);   // Initialize serial port for communication with host pc
  
  pinMode(FIRE_AC_LIGHT, OUTPUT); 
  pinMode(ZERO_CROSS,INPUT);
}

void loop() {
  if (Serial.available() > 0) {
    inputByte = Serial.read();
    dimValue = 255-inputByte;

  }

  if(digitalRead(ZERO_CROSS) == HIGH){
      int dimtime = (35.15*dimValue+1);  // 39.0625 => 10.000 Microseconds / 255    
      delayMicroseconds(dimtime);     // Off cycle
      digitalWrite(FIRE_AC_LIGHT, HIGH);   // triac firing
      delayMicroseconds(10);   
      digitalWrite(FIRE_AC_LIGHT, LOW);
  }
}
