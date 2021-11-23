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
void buzzer(int k)
{
 int j;
 for(j=0;j<k;j++){
 digitalWrite(buzzerPin,HIGH);
 delay(500);
 digitalWrite(buzzerPin,LOW);
 delay(500);}
}
