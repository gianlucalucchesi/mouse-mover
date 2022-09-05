#include <Mouse.h>

/*
    NAME: Arduino Mouse Jiggler
    DATE: 2019-09-18
    DESC: Arduino based mouse emulator
    VERSION: 1.0
*/

int move_interval = 10000; // 10 seconds
int x = 5; // 5 pixels on x-axis
int y = 0;
int z = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Mouse.begin();
  Mouse.move(x, y, z);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int n = 0; n < 2; n++) {
    if (n == 0) {
      // 5min long to the right every 10sec
      for (int i = 0; i < 30; i++) {
        Mouse.move(x, y, 0);
        delay(move_interval);
      }
    } else {
      // 5min long to the left every 10sec
      for (int i = 0; i < 30; i++) {
        Mouse.move(-x, y, 0);
        delay(move_interval);
      }
    }
  }
}
