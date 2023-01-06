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

char MenuSerial::OptionSelected()
{
  char option = 'o';
    if(!menuPrinted)
    {
      PrintMenu();
      menuPrinted = true;
    }
    while(!Serial.available())
    {
    }
    if(Serial.available()>0)
    {
      option = Serial.read();
    }
  menuPrinted = false;
  Serial.write("\n\n\n");
  return option;
}

void MenuSerial::ClearMenu()
{
  int i = 0;
  while(i<14)
  {
    Serial.println();
    i++;
  }
}