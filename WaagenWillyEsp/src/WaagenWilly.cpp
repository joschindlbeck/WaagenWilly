#include "WaagenWilly.h"

void WaagenWilly::weighing()
{
    Serial.println("Wiegen gedrueckt!");
    if (msgMode > 0)
    {
        // Are you sure message pending! We confirm with this button
        if (msgMode == MSG_MODE_DELETE_LAST)
        {
            // delete last weighing
            deleteLastWeightReally();
        }
        else if (msgMode == MSG_MODE_DELETE_ALL)
        {
            // delete all weighing
            deleteAllWeightReally();
        }
    }
    else
    {
        // normal mode - do weighing
        lastWeight = currentWeight; // Take current weight to last weight
        sumWeight += currentWeight;
        weighNum += 1;
        sumWeighNum += 1;

        refreshLCD();

        save();
    }
}

void WaagenWilly::deleteLastWeight()
{
    Serial.println("delete Last Weight");
    if (msgMode == MSG_MODE_NORMAL)
    {
        // are you sure message
        msgMode = MSG_MODE_DELETE_LAST;
        myLCD.writeMessage("Letze loeschen?");
    }else{
        // if in Message mode, we use this button as "cancel" button
        msgMode = MSG_MODE_NORMAL;
        myLCD.clearMessage();
    }
}

void WaagenWilly::deleteAllWeight()
{
    Serial.println("delete all");
    if (msgMode == MSG_MODE_NORMAL)
    {
        // are you sure message
        msgMode = MSG_MODE_DELETE_ALL;
        myLCD.writeMessage("Alle loeschen?");
    }
}

void WaagenWilly::deleteLastWeightReally()
{
    Serial.println("really delete Last Weight");
    sumWeight -= lastWeight;
    sumWeighNum -= 1;
    lastWeight = 0;
    msgMode = MSG_MODE_NORMAL;

    refreshLCD();
}

void WaagenWilly::deleteAllWeightReally()
{
    Serial.println("really delete all");

    lastWeight = 0;
    sumWeighNum = 0;
    sumWeight = 0;
    weighNum = 0;
    msgMode = MSG_MODE_NORMAL;

    refreshLCD();
}

void WaagenWilly::tara()
{
    Serial.println("tara");
}

void WaagenWilly::refreshLCD()
{
    myLCD.clearMessage();
    myLCD.writeWeighNum(currentWeight);
    myLCD.writeLastWeight(lastWeight);
    myLCD.writeSumWeighNum(sumWeighNum);
    myLCD.writeSumWeight(sumWeight);
    myLCD.writeWeighNum(weighNum);
}

void WaagenWilly::save(){
    /*
    //save to EEPROM
    EEPROM.write(0,sumWeight);
    EEPROM.write(0, sumWeighNum);
    EEPROM.commit();
    */

   // Save to NVS
   //NVS.setInt("sumWeighNum",sumWeighNum);
   //NVS.setInt("sumWeight", sumWeight);

    //Save prefs
    prefs.begin("willy", false);
    prefs.putInt("sumWeighNum",sumWeighNum);
    prefs.putInt("sumWeight", sumWeight);
    prefs.end();
}

void WaagenWilly::restore(){
    /*
    // read from EEPROM
    sumWeight = EEPROM.read(0);
    sumWeighNum = EEPROM.read(1);
    */

   //Read NVS
   //sumWeighNum = NVS.getInt("sumWeighNum");
   //sumWeight = NVS.getInt("sumWeight");

   //Read preferences
      sumWeighNum = prefs.getInt("sumWeighNum");
   sumWeight = prefs.getInt("sumWeight");
}

WaagenWilly::WaagenWilly(){
    //EEPROM.begin(8);
    //NVS.begin();
    prefs.begin("willy", false);
    restore();
}