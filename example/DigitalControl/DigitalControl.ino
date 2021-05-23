#include <Arduino.h>
#include "JsonAsyncComm.h"

JsonAsyncComm jsonComm;

int pin = 0;
int status = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String jsonMsg = Serial.readStringUntil('\n');
    jsonComm.updateDataBase(jsonMsg);
    jsonComm.getVariable(pin);
    jsonComm.getVariable(status);
  }
  
  pinMode(pin, OUTPUT);
  digitalWrite(pin, status);
}