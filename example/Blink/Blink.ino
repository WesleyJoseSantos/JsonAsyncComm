#include <JsonAsyncComm.h>

JsonAsyncComm jsonComm;

int pin = 0;
int status = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  jsonComm.setSendDataCallback([](String data){
    Serial.print(data);
  });

  jsonComm.setVariable(pin, 13);
}

void loop() {
  // put your main code here, to run repeatedly:
  jsonComm.setVariable(status, HIGH);
  delay(1000);
  jsonComm.setVariable(status, LOW);
  delay(1000);
}