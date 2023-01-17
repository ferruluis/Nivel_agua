#include <Arduino.h>
#define trig 0
#define echo 2


unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 60000;

void send(){};
unsigned long ultrasonido(){
  unsigned long t=0;
  unsigned long d=0;
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  return d;
};

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  digitalWrite(trig, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ultrasonido();
    send();
  
  }
}