#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3_ge34hqF"
#define BLYNK_TEMPLATE_NAME "smart praking system"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "VF8DQ5CqYg8tqiux3r3StxyGjYBf3L_8";
char ssid[] = "OnePlus"; //enter wifi name
char pass[] = "Password"; //enter wifi password

int IR_sensor1 = D0;
int IR_sensor2 = D1;
int IR_sensor3 = D2;
int IR_sensor4 = D3;
int IR_sensor5 = D4;
//int IR_sensor6 = D5;

int LED = D7;

WidgetLED led1(V0);// Virtual Pin V2
WidgetLED led2(V1);// Virtual Pin V3
WidgetLED led3(V2);
WidgetLED led4(V4);
WidgetLED led5(V5);
//WidgetLED led6(V6);

BlynkTimer timer;

void sensor1(){
  int value = digitalRead(IR_sensor1);
  if(value == HIGH){
    led1.on();
    digitalWrite(LED,HIGH);
  }
  else{
    led1.off();
    digitalWrite(LED,LOW);
  }  
}

void sensor2(){
  int value = digitalRead(IR_sensor2);
  if(value == HIGH){
    led2.on();
    digitalWrite(LED,HIGH);
  }
  else{
    led2.off();
    digitalWrite(LED,LOW);
  }  
}

void sensor3(){
  int value = digitalRead(IR_sensor3);
  if(value == HIGH){
    led3.on();
    digitalWrite(LED,HIGH);
  }
  else{
    led3.off();
    digitalWrite(LED,LOW);
  }  
}

void sensor4(){
  int value = digitalRead(IR_sensor4);
  if(value == HIGH){
    led4.on();
    digitalWrite(LED,HIGH);
  }
  else{
    led4.off();
    digitalWrite(LED,LOW);
  }  
}

void sensor5(){
  int value = digitalRead(IR_sensor5);
  if(value == HIGH){
    led5.on();
    digitalWrite(LED,HIGH);
  }
  else{
    led5.off();
    digitalWrite(LED,LOW);
  }  
}




void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(IR_sensor1,INPUT);
  pinMode(IR_sensor2,INPUT);
  pinMode(IR_sensor3,INPUT);
  pinMode(IR_sensor4,INPUT);
  pinMode(IR_sensor5,INPUT);
 // pinMode(IR_sensor6,INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(300L,sensor1);
  timer.setInterval(300L,sensor2);
  timer.setInterval(300L,sensor3);
  timer.setInterval(300L,sensor4);
  timer.setInterval(300L,sensor5);
  //timer.setInterval(300L,sensor6);
}

void loop()
{
  Blynk.run();
  timer.run();
}