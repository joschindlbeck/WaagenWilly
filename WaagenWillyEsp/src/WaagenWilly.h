#include <Arduino.h>
#include <WillyLCD.h>
#include <EEPROM.h>
#include <Preferences.h>


class WaagenWilly{

private:
void refreshLCD();
void deleteLastWeightReally();
void deleteAllWeightReally();
void save();
void restore();

public:

// Constanten
static const int MSG_MODE_NORMAL = 0;
static const int MSG_MODE_DELETE_LAST = 1;
static const int MSG_MODE_DELETE_ALL = 2;

// Gewichte
int currentWeight;
int lastWeight;
int sumWeight;
int weighNum;
int sumWeighNum;

// Applikationskomponenten
WillyLCD myLCD = WillyLCD();
int msgMode;
Preferences prefs;

void weighing();  //current Weight to last weight
void deleteLastWeight();
void deleteAllWeight();
void tara();
void areYouSureMsg(char msg[20]);
WaagenWilly();
};
