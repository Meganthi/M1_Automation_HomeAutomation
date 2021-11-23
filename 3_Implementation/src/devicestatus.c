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
void send_deviceStatus()
{

gsm.println("AT+CMGF=1");
 buzzer(2);
 gsm.println("AT+CMGS=\"+918129613637\"\r");
 buzzer(2);
 
 gsm.print("BULB 1 ");
 if(bulb_1Status==true)
 gsm.println("ON \n");
 if(bulb_1Status==false)
 gsm.println("OFF \n");


gsm.print("BULB 2 ");
 if(bulb_2Status==true)
 gsm.println("ON \n");
 if(bulb_2Status==false)
 gsm.println("OFF \n");


gsm.print("BULB 3 ");
 if(bulb_3Status==true)
 gsm.println("ON \n");
 if(bulb_3Status==false)
 gsm.println("OFF \n");


gsm.print("FAN ");
 if(fanStatus==true)
 gsm.println("ON \n");
 if(fanStatus==false)
 gsm.println("OFF \n");
 buzzer(2);
 
 gsm.println((char)26);
 buzzer(2);

gsm.println("AT+CNMI=2,2,0,0,0");
 buzzer(2);
}
