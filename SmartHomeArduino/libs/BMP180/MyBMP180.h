//MyBMP180.h

#ifndef MyBMP180_h
#define MyBMP180_h

#if defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__) || defined (__AVR_ATtiny84__)
  #include "TinyWireM.h"
  #define Wire TinyWireM
#else
  #include <Wire.h>
#endif

#include "Arduino.h"

#define BMP180_I2CADD_FIX  0x77  //Fix vorgegebene I2C-Adresse

#define BMP180_CTRL_MEAS_REG   0xF4
#define BMP180_START_TEMP_MEAS 0x2E
#define BMP180_OUT_MSB_REG     0xF6
#define BMP180_START_PRES_MEAS 0x34

#define BMP180_ULTRA_LOW_POWER       0
#define BMP180_STANDARD              1
#define BMP180_HIGH_RESOLUTION       3
#define BMP180_ULTRA_HIGH_RESOLUTION 4

class MyBMP180
{
  public:
    MyBMP180(void);
    MyBMP180(byte);
    bool isReady(void);
    void init(byte);
    float readTemp(void);
    float readPress(void);
    float readReducedPress(int);
    
  private:
    int readKoeff(byte adr);
    int ac1, ac2, ac3, b1, b2, mb, mc, md;
    unsigned int ac4, ac5, ac6;
    long x1, x2, x3, b3, b5, b6;
    unsigned long b4, b7;
    byte temp_delay;
    byte pres_delay;
    long ut;
    long up;
    long t;
    long p;
    byte _i2cAdd;
    byte _oss;
    float press;
    float temp;
    float redPress; //reduzierter Druck
 };

#endif

