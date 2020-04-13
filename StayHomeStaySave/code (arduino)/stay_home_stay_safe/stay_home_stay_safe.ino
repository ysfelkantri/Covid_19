/*****************************************************************************
         Copyright  EL KANTRI Youssef  All Rights Reserved
*****************************************************************************/

/*****************************************************************************
     Header Files included
 *****************************************************************************/

#include <LiquidCrystal.h>

/******************************************************************************
   PROJECT :  stay Safe lcd implementation
 ******************************************************************************
 *                                                                            *
    Written by  : EL KANTRI Youssef                       Date : 09/03/2020
 *                                                                            *
    Email : ysfelkantri1998@gmail.com
 ******************************************************************************
   MODIFICATION LOG:
 ******************************************************************************
   Modified by :                                           Date :
   Comments :
 ******************************************************************************/


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("#Stay Home");
  lcd.setCursor(0, 1);
  lcd.print("#Stay Safe");
}

void loop() {

}
