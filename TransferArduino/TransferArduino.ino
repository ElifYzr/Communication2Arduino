
const int lm35=A0;
float voltage_value=0;
float temp=0;
float temp_read=0;
const int pot_pin= A1;
int value=0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
lcd.begin (16,2);


}

void loop() {
  // put your main code here, to run repeatedly:
temp_read=analogRead(A0);
voltage_value= (temp_read/1023.0)*5000;
temp=voltage_value/10.0;
value=analogRead(A1);
Serial.println("Voltage=" + String(value));
Serial.println("Temp=" + String(temp));
lcd.clear();
lcd.home();
lcd.print("Temp= ");
lcd.setCursor(5,0);
lcd.print(temp);
lcd.print("degree");
lcd.setCursor(0,1);
lcd.print("Voltage= ");
lcd.setCursor(8,1);
lcd.print(value);
lcd.print("mV");
delay(1000);
}
