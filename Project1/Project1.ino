
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

//lcd colour
const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    Serial.begin(9600);
    
    lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
    //change temperature to celcius
    float voltage = analogRead(A0) *  (5000/ 1024);
    float temperature = (voltage - 500)/50;
    //show temperature on lcd screen
    lcd.setCursor(0, 0);
    lcd.print(temperature);
    delay(100);
    
    //decide if oven is hot enough to cook
    if(temperature<160)
    {
      lcd.setCursor(0, 1);
      lcd.print("Oven NOT Ready");
    }
    if(temperature>=160)
    {
      lcd.setCursor(0, 1);
      lcd.print("Oven Ready      ");
    }
}



/*********************************************************************************************************
    END FILE
*********************************************************************************************************/
