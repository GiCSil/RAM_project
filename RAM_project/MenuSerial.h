#include <Arduino.h>

class MenuSerial
{
  private:
  bool menuPrinted = false;
  void PrintMenu();
  public:
  char OptionSelected();
  void ClearMenu();
}