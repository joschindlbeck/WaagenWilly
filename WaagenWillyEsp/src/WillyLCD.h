// Klassendeklarationen für WaagenWilly

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Defines für PINS


class WillyLCD
{
private:
    LiquidCrystal_I2C lcd;  // Liquid Crystal LCD

public:
    WillyLCD();
    ~WillyLCD();
    void sayHello();
    void writeCurrentWeight(int w);
    void writeLastWeight(int w);
    void writeSumWeight(int w);
    void writeWeighNum(int n);
    void writeSumWeighNum(int n);
    void writeMessage(char msg[20]);
    void init();
    void clearMessage();

};





