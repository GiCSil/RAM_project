#include <Arduino.h>

class MenuSerial
{
  private:
    bool menuPrinted = false;
    void PrintMenu();
  public:
    MenuSerial();
    ~MenuSerial();
    char OptionSelected();
    void ClearMenu();
};