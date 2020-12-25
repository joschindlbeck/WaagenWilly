// Implementierung

#include <WillyLCD.h>

WillyLCD::WillyLCD()
{
    LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);
}

WillyLCD::~WillyLCD()
{
}

void WillyLCD::sayHello()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello Willy");
}

/**
 * Initialization of LCD
*/
void WillyLCD::init() {
    lcd.begin(20, 4);
    lcd.clear();
    lcd.setCursor(0,0);
    //lcd.print("WaagenWilly 0.1");
}

void WillyLCD::writeCurrentWeight(int w) {
    //lcd.begin(20,4);
    lcd.setCursor(12,0);
    lcd.printf("%5u kg", w);   
}

void WillyLCD::writeLastWeight(int w) {
    //lcd.begin(20,4);
    lcd.setCursor(10,1);
    lcd.printf("L %5u kg", w);   
}

void WillyLCD::writeSumWeight(int w) {
    //lcd.begin(20,4);
    lcd.setCursor(10,2);
    lcd.printf("S %5u kg", w);    
}

void WillyLCD::writeWeighNum(int n) {
    //lcd.begin(20,4);
    lcd.setCursor(0, 1);
    lcd.printf("#  %3u", n);  
}

void WillyLCD::writeSumWeighNum(int n) {
    //lcd.begin(20,4);
    lcd.setCursor(0, 2);
    lcd.printf("S# %3u", n);  
}

void WillyLCD::writeMessage(char msg[20]){
    clearMessage();
    lcd.setCursor(0,3);
    lcd.print(msg);

}

void WillyLCD::clearMessage(){
    lcd.setCursor(0,3);
    lcd.print("                    ");
}
