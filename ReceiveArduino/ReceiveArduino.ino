#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float temp;
int value;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
lcd.begin (16,2);
while (!Serial);
}

void loop() {
  while (Serial.available()>0){
    String data=Serial.readStringUntil('\n');
    if (data.startsWith("Temp=")){
      temp=data.substring (5, data.length()).toFloat();
    
    
  } else if (data.startsWith("Voltage=")){
value=data.substring(8,data.length()).toFloat();
  }
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Temp= ");
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("value=");
  lcd.print(value);

}}
