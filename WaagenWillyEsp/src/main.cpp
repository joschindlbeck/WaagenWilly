#include <Arduino.h>
#include <WaagenWilly.h>
#include <Button2.h>


// -- Button PINS --
#define WEIGHING_PIN 23 //Button 1
#define DELETE_PIN 18   // Button2
#define TARA_PIN 03     // Button 3

// -- Globals
WaagenWilly willy = WaagenWilly();

Button2 weighingButton = Button2(WEIGHING_PIN);
Button2 deleteButton = Button2(DELETE_PIN);
Button2 taraButton = Button2(TARA_PIN);

//Callback Wiegen
void weighing(Button2& btn){
  Serial.println("click");
}


// -- Setup
void setup()
{
  // put your setup code here, to run once:
  willy.myLCD.init();
  weighingButton.setClickHandler([](Button2& btn){ willy.weighing();});
  deleteButton.setClickHandler([](Button2& btn){ willy.deleteLastWeight();});
  deleteButton.setLongClickHandler([](Button2& btn){ willy.deleteAllWeight();});
  taraButton.setClickHandler([](Button2& btn){ willy.tara();});
  Serial.begin(115200);


  // test
    willy.currentWeight = rand() % 1000;
  Serial.println(willy.currentWeight);

    willy.myLCD.writeCurrentWeight(willy.currentWeight);
  willy.myLCD.writeLastWeight(willy.lastWeight);
  willy.myLCD.writeSumWeight(willy.sumWeight);
  willy.myLCD.writeWeighNum(willy.weighNum);
  willy.myLCD.writeSumWeighNum(willy.sumWeighNum);
}
// -- Loop
void loop()
{
  // put your main code here, to run repeatedly:


  //button loops
  weighingButton.loop();
  deleteButton.loop();
  taraButton.loop();

}
