//MyBMP180.cpp
//Code fuer Arduino und Attiny85
//Author Retian
//Version 2.1

/*
Abfrage eines Luftdrucksensors BMP180 ueber I2C-Schnittstelle.

MyBMP180 Name(I2C-Adresse);

Beispiel siehe unter:
http://arduino-projekte.webnode.at/meine-libraries/luftdrucksensor-bmp180/

Funktionen siehe unter:
http://arduino-projekte.webnode.at/meine-libraries/luftdrucksensor-bmp180/funktionen/

*/

//*************************************************************************
//*************************************************************************

#include "Arduino.h"
#include "MyBMP180.h"

MyBMP180::MyBMP180()
{
  _i2cAdd  = BMP180_I2CADD_FIX;
  Wire.begin();
}


MyBMP180::MyBMP180(byte i2cAdd)
{
  _i2cAdd  = i2cAdd;
  Wire.begin();
}

//*************************************************************************
//BMP180 vorhanden ?

bool MyBMP180::isReady()
{
  Wire.beginTransmission(_i2cAdd);
  if (Wire.endTransmission()== 0) return true;
  else return false;
}

//*************************************************************************
// BMP180 initialisiern (Kalibrieungskoeffizienten einlesen)
void MyBMP180::init(byte oss)
{
  _oss = oss;

  switch(_oss)
  {
    case BMP180_ULTRA_LOW_POWER:
      pres_delay = 5;
      break;
    case BMP180_STANDARD:
      pres_delay = 8;
      break;
    case BMP180_HIGH_RESOLUTION:
      pres_delay = 14;
      break;
    case BMP180_ULTRA_HIGH_RESOLUTION:
      pres_delay = 26;
      break;
  }

  temp_delay = 5; //ms
  
  ac1 = readKoeff(0xAA);
  ac2 = readKoeff(0xAC);
  ac3 = readKoeff(0xAE);
  ac4 = readKoeff(0xB0);
  ac5 = readKoeff(0xB2);
  ac6 = readKoeff(0xB4);
  b1 = readKoeff(0xB6);
  b2 = readKoeff(0xB8);
  mb = readKoeff(0xBA);
  mc = readKoeff(0xBC);
  md = readKoeff(0xBE);

  /*
  Serial.print("ac1 ");
  Serial.println(ac1);
  Serial.print("ac2 ");
  Serial.println(ac2);
  Serial.print("ac3 ");
  Serial.println(ac3);
  Serial.print("ac4 ");
  Serial.println(ac4);
  Serial.print("ac5 ");
  Serial.println(ac5);
  Serial.print("ac6 ");
  Serial.println(ac6);
  Serial.print("b1 ");
  Serial.println(b1);
  Serial.print("b2 ");
  Serial.println(b2);
  Serial.print("mb ");
  Serial.println(mb);
  Serial.print("mc ");
  Serial.println(mc);
  Serial.print("md ");
  Serial.println(md);
  */
}

//*************************************************************************
//Umgebungstemperatur ermitteln

float MyBMP180::readTemp()
{
  byte msb, lsb;

  //Starte Temperaturmessung
  Wire.beginTransmission(_i2cAdd);
  Wire.write(BMP180_CTRL_MEAS_REG);
  Wire.write(BMP180_START_TEMP_MEAS);
  Wire.endTransmission();
  
  delay(temp_delay);
  
  //Lese Temperatur-Rohwert
  Wire.beginTransmission(_i2cAdd);
  Wire.write(BMP180_OUT_MSB_REG);
  Wire.endTransmission();
  Wire.requestFrom(_i2cAdd, (byte)2);
  msb = Wire.read();
  lsb = Wire.read();

  ut = ((long)msb << 8) + ((long)lsb);
  
  //Berechne Temperatur
  x1 = (ut - (long)ac6) * (long)ac5 >> 15;
  x2 = ((long)mc << 11) / (x1 + (long)md);
  b5 = x1 + x2;
  t = (b5 + 8) >> 4;
  return temp = t / 10.0;
}

//*************************************************************************
//Luftdruck am Standort ermitteln

float MyBMP180::readPress()
{
  byte msb, lsb, xlsb;

  //Starte Druckmessung
  Wire.beginTransmission(_i2cAdd);
  Wire.write(BMP180_CTRL_MEAS_REG);
  Wire.write(BMP180_START_PRES_MEAS + (_oss << 6));
  Wire.endTransmission();

  delay(pres_delay);
  
  //Lese Druck-Rohwert
  Wire.beginTransmission(_i2cAdd);
  Wire.write(BMP180_OUT_MSB_REG);
  Wire.endTransmission();
  Wire.requestFrom(_i2cAdd, (byte)3);
  msb = Wire.read();
  lsb = Wire.read();
  xlsb = Wire.read();

  up = (((long)msb << 16) | ((long)lsb << 8) | ((long)xlsb)) >> (8 - _oss);
  
  //Berechne Luftdruck
  b6 = b5 - 4000;
  //Serial.print("b6 ");
  //Serial.println(b6);
  x1 = (b2 * (b6 * b6 >> 12)) >> 11;
  //Serial.print("x1 ");
  //Serial.println(x1);
  x2 = ac2 * b6 >> 11;
  //Serial.print("x2 ");
  //Serial.println(x2);
  x3 = x1 + x2;
  //Serial.print("x3 ");
  //Serial.println(x3);
  b3 = (((unsigned long)(ac1 * 4 + x3) << _oss) + 2) >> 2;
  //Serial.print("b3 ");
  //Serial.println(b3);
  x1 = ac3 * b6 >> 13;
  //Serial.print("x1 ");
  //Serial.println(x1);
  x2 = (b1 * (b6 * b6 >> 12)) >> 16;
  //Serial.print("x2 ");
  //Serial.println(x2);
  x3 = ((x1 + x2) + 2) >> 2;
  //Serial.print("x3 ");
  //Serial.println(x3);
  b4 = (ac4 * (unsigned long)(x3 + 32768)) >> 15;
  //Serial.print("b4 ");
  //Serial.println(b4);
  b7 = ((unsigned long)up - b3) * (50000 >> _oss);
  //Serial.print("b7 ");
  //Serial.println(b7);
  if (b7 < 0x80000000) p = (b7 << 1) / b4;
  else p = (b7 / b4) << 1;
  //Serial.print("p ");
  //Serial.println(p);
  x1 = (p  >> 8) * (p >> 8);
  //Serial.print("x1 ");
  //Serial.println(x1);
  x1 = (x1 * 3038) >> 16;
  //Serial.print("x1 ");
  //Serial.println(x1);
  x2 = (-7357 * p) >> 16;
  //Serial.print("x2 ");
  //Serial.println(x2);
  p = p + ((x1 + x2 + 3791) >> 4);
  return press = p / 100.0;
}

//*************************************************************************
//Reduzierten Luftdruck bezogen auf Meereshoehe ermitteln

float MyBMP180::readReducedPress(int hoehe)
{
  //Berechne reduzierten Luftdruck
  int _hoehe = hoehe;

  readPress();
  return redPress = (press / (pow((1 - (_hoehe / 44330.0)), 5.255)));
}

//*************************************************************************
// Einlesen von 2 Bytes ueber die I2C-Schnittstelle aus dem EEprom des BMP180(interne Verwendung)

int MyBMP180::readKoeff(byte adr)
{
  byte _adr = adr;

  Wire.beginTransmission(_i2cAdd);
  Wire.write(_adr);
  Wire.endTransmission();
  Wire.requestFrom(_i2cAdd, (byte)2);
  return (Wire.read() << 8) | Wire.read();
}






