#include "lucky7.h"
#include "IRremote.h"

IRrecv irrecv(IR);
decode_results results;

void Lucky7::setup() {
  o1 = 0;
  o2 = 0;
  o3 = 0;
  o4 = 0;
  o5 = 0;
  o6 = 0;
  o7 = 0;
  o8 = 0;
  o13 = 0;
  pinMode(O1,OUTPUT);
  pinMode(O2,OUTPUT);
  pinMode(O3,OUTPUT);
  pinMode(O4,OUTPUT);
  pinMode(O5,OUTPUT);
  pinMode(O6,OUTPUT);
  pinMode(O7,OUTPUT);
  pinMode(O8,OUTPUT);
  pinMode(O13,OUTPUT);
  timeout = 0;

  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  aveptr = 0;

  irrecv.enableIRIn(); // Start the receiver
}


uint32_t Lucky7::loop() {
  uint8_t i = (aveptr++) % AVECNT;
  uint32_t rv = 0;
  analogWrite(O1,o1);
  analogWrite(O2,o2);
  analogWrite(O3,o3);
  digitalWrite(O4,o4);
  analogWrite(O5,o5);
  analogWrite(O6,o6);
  analogWrite(O7,o7);
  digitalWrite(O8,o8);
  digitalWrite(O13,o13);

  pc1[i] = analogRead(A4);
  pc2[i] = analogRead(A5);
  bc[i]  = analogRead(A0);

  if (millis() > timeout) {
      if (irrecv.decode(&results)) {
        rv = results.value;
        timeout = millis() + 500;
      }
    } else {
      irrecv.resume(); // Receive the next value
    }
  return rv;
}

uint16_t Lucky7::photocell1() {
    uint16_t sum = 0;
    uint8_t i;
    for (i = 0; i < AVECNT; i++) {
        sum += pc1[i];
    }
    return (uint16_t)(sum/AVECNT);
}

uint16_t Lucky7::photocell2() {
    uint32_t sum = 0;
    uint8_t i;
    for (i = 0; i < AVECNT; i++) {
        sum += pc2[i];
    }
    return (uint16_t)(sum/AVECNT);
}

float Lucky7::batteryVoltage() {
    uint32_t sum = 0;
    uint8_t i;
    for (i = 0; i < AVECNT; i++) {
        sum += bc[i];
    }
    return (float)(sum/AVECNT)*BVSCALE;
}


// this could be done more efficiently
void Lucky7::o1MoveTo(uint8_t v, uint16_t stepdelay) {
    int16_t i;
    if (v == o1) {
        return;
    } 
    if (v > o1) {
        for (i = o1; i < v; i++) {
            //Serial.println(i);
            analogWrite(O1,i);
            delayMicroseconds(stepdelay);
        }
    } else {
        for (i = o1; i >= v; i--) {
            //Serial.println(i);
            analogWrite(O1,i);
            delayMicroseconds(stepdelay);
        }
    }
    o1 = v;
}

// this could be done more efficiently
void Lucky7::o2MoveTo(uint8_t v, uint16_t stepdelay) {
    int16_t i;
    if (v == o2) {
        return;
    } 
    if (v > o2) {
        for (i = o2; i < v; i++) {
            //Serial.println(i);
            analogWrite(O2,i);
            delayMicroseconds(stepdelay);
        }
    } else {
        for (i = o2; i >= v; i--) {
            //Serial.println(i);
            analogWrite(O2,i);
            delayMicroseconds(stepdelay);
        }
    }
    o2 = v;
}

// this could be done more efficiently
void Lucky7::o3MoveTo(uint8_t v, uint16_t stepdelay) {
    int16_t i;
    if (v == o3) {
        return;
    } 
    if (v > o3) {
        for (i = o3; i < v; i++) {
            //Serial.println(i);
            analogWrite(O3,i);
            delayMicroseconds(stepdelay);
        }
    } else {
        for (i = o3; i >= v; i--) {
            //Serial.println(i);
            analogWrite(O3,i);
            delayMicroseconds(stepdelay);
        }
    }
    o3 = v;
}

// this could be done more efficiently
void Lucky7::o5MoveTo(uint8_t v, uint16_t stepdelay) {
    int16_t i;
    if (v == o5) {
        return;
    } 
    if (v > o5) {
        for (i = o5; i < v; i++) {
            //Serial.println(i);
            analogWrite(O5,i);
            delayMicroseconds(stepdelay);
        }
    } else {
        for (i = o5; i >= v; i--) {
            //Serial.println(i);
            analogWrite(O5,i);
            delayMicroseconds(stepdelay);
        }
    }
    o5 = v;
}

// this could be done more efficiently
void Lucky7::o6MoveTo(uint8_t v, uint16_t stepdelay) {
    int16_t i;
    if (v == o6) {
        return;
    } 
    if (v > o6) {
        for (i = o6; i < v; i++) {
            //Serial.println(i);
            analogWrite(O6,i);
            delayMicroseconds(stepdelay);
        }
    } else {
        for (i = o6; i >= v; i--) {
            //Serial.println(i);
            analogWrite(O6,i);
            delayMicroseconds(stepdelay);
        }
    }
    o6 = v;
}

// this could be done more efficiently
void Lucky7::o7MoveTo(uint8_t v, uint16_t stepdelay) {
    int16_t i;
    if (v == o7) {
        return;
    } 
    if (v > o7) {
        for (i = o7; i < v; i++) {
            //Serial.println(i);
            analogWrite(O7,i);
            delayMicroseconds(stepdelay);
        }
    } else {
        for (i = o7; i >= v; i--) {
            //Serial.println(i);
            analogWrite(O7,i);
            delayMicroseconds(stepdelay);
        }
    }
    o7 = v;
}
