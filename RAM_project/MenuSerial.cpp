#include "MenuSerial.h"

void MenuSerial::PrintMenu()
{
  // menu options
  Serial.println("Menu Selection:");
  Serial.println("1 - Register User");
  Serial.println("2 - List of Users");
  Serial.println("3 - List of Events");
  Serial.println("4 - Access Door 1");
  Serial.println("5 - Access Door 2");
}

MenuSerial::MenuSerial()
{
}

MenuSerial::~MenuSerial()
{
}

char MenuSerial::OptionSelected()
{
  char option = 'o';
    if(!menuPrinted)              // checks if you have to print the menu
    {
      PrintMenu();
      menuPrinted = true;
    }
    while(!Serial.available())    // does nothing if the serial port is unavailable
    {
    }
    if(Serial.available()>0)
    {
      option = Serial.read();     // reads the serial console
    }
  menuPrinted = false;
  Serial.write("\n\n\n");
  return option;
}

void MenuSerial::ClearMenu()      // just clear a little of the serial
{
  int i = 0;
  while(i<14)
  {
    Serial.println();
    i++;
  }
}