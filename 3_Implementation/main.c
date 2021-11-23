/**
 * @file main.c
 * @author meganthi
 * @brief 
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
int i=0;
String incomingString="", device="";
char character,buf[100]=""; 
boolean bulb_1Status = false, bulb_2Status = false, bulb_3Status = false, fanStatus = false;
long previous_millis=0;

void setup()
{
 
 Serial.begin(9600);
 lcd.begin(16,2);
 gsm.begin(9600);

pinMode(bulb_1Pin,OUTPUT);
 pinMode(bulb_2Pin,OUTPUT);
 pinMode(bulb_3Pin,OUTPUT);
 pinMode(fanPin,OUTPUT);
 pinMode(buzzerPin,OUTPUT);

digitalWrite(bulb_1Pin,LOW);
 digitalWrite(bulb_2Pin,LOW);
 digitalWrite(bulb_3Pin,LOW);
 digitalWrite(fanPin,LOW);
 digitalWrite(buzzerPin,LOW);

lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(" GSM BASED ");
 lcd.setCursor(0,1);
 lcd.print(" HOME AUTOMATION");
 delay(2000);
 
}
void loop()
{
 
top: 
 lcd.begin(16,2);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(" DEVICE STATUS ");

gsm.println("AT+CNMI=2,2,0,0,0");



 while(1)
 {

incomingString="";
 digitalWrite(bulb_1Pin,bulb_1Status);
 digitalWrite(bulb_2Pin,bulb_2Status);
 digitalWrite(bulb_3Pin,bulb_3Status);
 digitalWrite(fanPin,fanStatus);


 
 i=0;
 while(i<4){
 if(millis()-previous_millis > 2000)
 {
 previous_millis = millis();

if(i==0){
 lcd.setCursor(0,1);
 lcd.print(" BULB 1 ");
 if(bulb_1Status==true)
 lcd.print("ON ");
 if(bulb_1Status==false)
 lcd.print("OFF ");}

if(i==1){
 lcd.setCursor(0,1);
 lcd.print(" BULB 2 ");
 if(bulb_2Status==true)
 lcd.print("ON ");
 if(bulb_2Status==false)
 lcd.print("OFF ");}

if(i==2){
 lcd.setCursor(0,1);
 lcd.print(" BULB 3 ");
 if(bulb_3Status==true)
 lcd.print("ON ");
 if(bulb_3Status==false)
 lcd.print("OFF ");}

if(i==3){
 lcd.setCursor(0,1);
 lcd.print(" FAN ");
 if(fanStatus==true)
 lcd.print("ON ");
 if(fanStatus==false)
 lcd.print("OFF ");}
 i++;
 }
 


if(gsm.available())
 {
 if(gsm.read()=='*')
 {
 while(!gsm.available()){}
 
 incomingString += gsm.readStringUntil('#'); 
 // Serial.println(incomingString); 
 }
 
 }

if(incomingString.equals("B1ON")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" BULB 1 ON "); buzzer(5); bulb_1Status = true; goto top;}
 if(incomingString.equals("B2ON")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" BULB 2 ON "); buzzer(5); bulb_2Status = true; goto top;}
 if(incomingString.equals("B3ON")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" BULB 3 ON "); buzzer(5); bulb_3Status = true; goto top;}
 if(incomingString.equals("FON")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" FAN ON "); buzzer(5); fanStatus = true; goto top;}
 
 if(incomingString.equals("B1OFF")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" BULB 1 OFF "); buzzer(5); bulb_1Status = false; goto top;}
 if(incomingString.equals("B2OFF")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" BULB 1 OFF "); buzzer(5); bulb_2Status = false; goto top;}
 if(incomingString.equals("B3OFF")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" BULB 1 OFF "); buzzer(5); bulb_3Status =false; goto top;}
 if(incomingString.equals("FOFF")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1); lcd.print(" FAN OFF "); buzzer(5); fanStatus = false; goto top;}

if(incomingString.equals("STATUS")) { lcd.setCursor(0,0); lcd.print(" SMS RECEIVED "); lcd.setCursor(0,1);lcd.print(" SENDING STATUS ");send_deviceStatus(); goto top;}


}  } }

