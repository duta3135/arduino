#include <Arduino.h>
#include "TM1637.h"
#define clk 3
#define dio 2
#define btn 8
int number = 0;
TM1637 tm(clk, dio);
void setup()
{
  tm.init();
  tm.set(7);
}
void displayNumber(int num)
{
  pinMode(btn, INPUT);
  tm.display(3, num % 10);
  tm.display(2, num / 10 % 10);
  tm.display(1, num / 100 % 10);
  tm.display(0, num / 1000 % 10);
}
void loop()
{
  if (digitalRead(btn) == HIGH)
  {
    number++;
  }
  displayNumber(number);
}
