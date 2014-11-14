#ifndef LUCKY7_H
#define LUCKY7_H
#include "Arduino.h"

#define OFF 0
#define ON  255

// PWM outputs
#define O1  11
#define O2  10
#define O3  9
#define O5  6
#define O6  5
#define O7  3

#define O4  7      
#define O8  8
#define O13 13

#define IR  2

#define AVECNT 10

// ((5/1024)/10000)*43000 ideal
// 12.16/553
#define BVSCALE 0.02198915009

class Lucky7
{
private:
  uint32_t timeout;
  uint16_t pc1[AVECNT], pc2[AVECNT], bc[AVECNT];
  uint8_t aveptr;
public:
  uint8_t o1,o2,o3,o4,o5,o6,o7,o8,o13;

  void setup();

  uint32_t loop();

  void o1On()             {o1 = ON;}
  void o1Set(uint8_t v)   {o1 = v;}
  void o1Off()            {o1 = 0;}
  void o1MoveTo(uint8_t v,uint16_t stepdelay);
  void o1Toggle()         {o1 = o1?OFF:ON;};       
  
  void o2On()             {o2 = ON;}
  void o2Set(uint8_t v)   {o2 = v;}
  void o2Off()            {o2 = 0;}
  void o2MoveTo(uint8_t v,uint16_t stepdelay);
  void o2Toggle()         {o2 = o2?OFF:ON;};       

  void o3On()             {o3 = ON;}
  void o3Set(uint8_t v)   {o3 = v;}
  void o3Off()            {o3 = 0;}
  void o3MoveTo(uint8_t v,uint16_t stepdelay);
  void o3Toggle()         {o3 = o3?OFF:ON;};       

  void o4On()             {o4 = ON;}
  void o4Set(uint8_t v)   {o4 = v;}
  void o4Off()            {o4 = 0;}
  void o4Toggle()         {o4 = o4?OFF:ON;};       

  void o5On()             {o5 = ON;}
  void o5Set(uint8_t v)   {o5 = v;}
  void o5Off()            {o5 = 0;}
  void o5MoveTo(uint8_t v,uint16_t stepdelay);
  void o5Toggle()         {o5 = o5?OFF:ON;};       

  void o6On()             {o6 = ON;}
  void o6Set(uint8_t v)   {o6 = v;}
  void o6Off()            {o6 = 0;}
  void o6MoveTo(uint8_t v,uint16_t stepdelay);
  void o6Toggle()         {o6 = o6?OFF:ON;};       

  void o7On()             {o7 = ON;}
  void o7Set(uint8_t v)   {o7 = v;}
  void o7Off()            {o7 = 0;}
  void o7MoveTo(uint8_t v,uint16_t stepdelay);
  void o7Toggle()         {o7 = o7?OFF:ON;};       

  void o8On()             {o8 = ON;}
  void o8Set(uint8_t v)   {o8 = v;}
  void o8Off()            {o8 = 0;}
  void o8Toggle()         {o8 = o8?OFF:ON;};       

  void o13On()            {o13 = ON;}
  void o13Set(uint8_t v)  {o13 = v;}
  void o13Off()           {o13 = 0;}
  void o13Toggle()        {o13 = o13?OFF:ON;};       

  uint16_t photocell1();
  uint16_t photocell2();

  float batteryVoltage();

};
#endif


