#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
int moistPin = A0;
int wPump = 8;
float moistVal = 0;
int dt = 60000;
int dt1 = 5000;




void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.backlight();
  

  pinMode(moistPin, INPUT);
  pinMode(wPump, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:

  moistVal = analogRead(moistPin); 
  moistVal = moistVal / 100;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Soil Moisture:");
  lcd.print(moistVal); 
  lcd.print(" %");
  

 if (moistVal > 4.75){

   lcd.clear();
   digitalWrite(wPump, HIGH);
   lcd.setCursor(0,0);
   lcd.print("Watering");
   Serial.println(moistVal);
   
   delay(dt1);
   
   lcd.clear();
   digitalWrite(wPump, LOW);
   lcd.setCursor(0,0);
   lcd.print("Reading");
   Serial.println(moistVal);

   delay(dt1);
   

   
 } else {
    digitalWrite(wPump, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Moisture%: ");
    lcd.print(moistVal); 
    lcd.print("%");
    Serial.println(moistVal);
    
 }
   delay(dt1); 
 }



  
 
