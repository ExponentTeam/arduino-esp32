#include <WiFi.h>
#include <HTTPClient.h>


#define RXp2 0
#define TXp2 1

char ssid[] = "25252525";
char pass[] = "01012015";

int led = 13 ;
String command;

void setup (){
  Serial.begin(9600);
  pinMode (led, OUTPUT) ;
  Serial.println(" ");
  Serial.println("Trying to connect to WiFi named:");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
//  while(WiFi.status() != WL_CONNECTED){
//    Serial.print(".");
//    delay(500);
//    Serial.print(".");
//    delay(500);
//    Serial.print(".");
//    delay(500);
//    Serial.print(". ");
//    delay(5000);
//  }
  Serial.println("Everything is going just fine");
  Serial.println("Type command: \n >shock on (simulate shock sensor on) \n >shock off (simulate shock sensor off) \n >movement on (simulate movemont sensor on) \n >movement off (simulate movemont sensor off)");
}

void loop (){
  if(Serial.available()){
    command = Serial.readStringUntil('\n');
    command.trim();
    if(command.equals("shock on")){
      Serial.println("You just triggered shock sensor");
      Serial.println("alarm");
      digitalWrite(led, HIGH);
      } else if(command.equals("shock off")){
        Serial.println("You just stopped trigger of shock sensor");
        digitalWrite(led, LOW);
        }
    }
}
