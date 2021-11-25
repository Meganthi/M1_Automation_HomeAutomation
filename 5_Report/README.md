Home Automation


INTRODUCTION
       
       This project is about implementation of a wireless real-time home automation system based on Arduino and GSM module.This project is about building a home automation system,where the user can control the home appliances by simple phone including a GSM module,just by sending SMS through the phone.In this project just a old phone using GSM is enough to switch ON and OFF any home appliances from anywhere.
       
SWOT ANALYSIS

             Strength      : Save time with automated task.
             
             Weakness      : Reliable internet connection is crucial.
             
             Opportunities : This project is control the home appliances from anywhere.
             
             Threat        : Security issues, malware attack.
             
             4 W's and 1H
             
             who: 
             
                 This project is useful for the people who looks for control home appliances and saving electricity.
                 
             What:
             
                 This project increases power saving.
                 
              When:
              
                  This project is used for handicap and aged people.
             
              How :
              
                  This project works on a mobile phone.
                  
  HIGH LEVEL REQUIREMENTS
  
                1. ID          : HLR_01
                
                   DESCRIPTION : Visual Studio code platform.
                   
                   PLATFORM    : Software.
                   
                2. ID          : HLR_02
                
                   DESCRIPTION : Window 10 or Linux
                   
                   PLATFORM    : Software.
                   
                3. ID          : HLR_03
                
                   DESCRIPTION : Arduino
                   
                   PLATFORM    : Software
                   
   LOW LEVEL REQUIREMENTS
   
                1. ID          : LLR_01
                
                   DESCRIPTION : ON
                   
                2. ID          : LLR_02
                
                   DESCRIPTION : OFF
                   
    Main Function
    
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
