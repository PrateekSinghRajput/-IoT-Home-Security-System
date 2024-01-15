
//Prateek
//www.prateeks.in

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <SimpleTimer.h>

char auth[] = "6497f4ca052e43e377157926730";
char ssid[] = "justdoelectronics";
char pass[] = "pratik123";

SimpleTimer timer;

void myTimerEvent() {

  Blynk.virtualWrite(V2, millis() / 1000);
}

int ir_s = 0;

void setup() {

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(ir_s, INPUT);
  timer.setInterval(1000L, sensorvalue1);
}

void loop() {
  Blynk.run();
  timer.run();
}

void sensorvalue1() {

  if (digitalRead(ir_s) == LOW) {
    Blynk.virtualWrite(V1, 255);  // turns on the led
    Blynk.virtualWrite(V2, "Person detected on IR Sensor!!!");
    Blynk.notify("Person detected on IR Sensor!!!");
  }

  if (digitalRead(ir_s) == HIGH) {
    Blynk.virtualWrite(V1, 0);  // turns off the led
  }
}
