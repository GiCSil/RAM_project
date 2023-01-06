//Room Access Management Challenge
//Author: Giovane Carvalho Silvério
//06/01/2023

//-- Includes --
#include "MenuSerial.h"
#include "User.h"
#include "AccessEvent.h"

//-- Declarations --
MenuSerial menu;
User user;
AccessEvent event;
char menuSelection;           // selects the menu function
bool stopInstruction = true;  // stop instruction

//-- Definitions --
#define DOOR_ONE 7  // defines de output to open the door 1
#define DOOR_TWO 8  // defines de output to open the door 2

//-- Setup --
void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(DOOR_ONE, OUTPUT);
  pinMode(DOOR_TWO, OUTPUT);
}

//-- Main Loop --
void loop()
{
  if(stopInstruction)
  {
    menu.ClearMenu();
    menuSelection = menu.OptionSelected();
  }
  stopInstruction = false;
  while(!stopInstruction)
  {
    switch (menuSelection)
    {
      case '1':
      user.AddUser();
      break;
      case '2':
      user.UserList();
      break;
      case '3':
      user.EventList();
      break;
      case '4':
      user.AccessDoorOne();
      break;
      case '5':
      user.AccessDoorTwo();
      break;
      default:
      Serial.println("The option selected does not exists. Try again.");
      break;
    }
    stopInstruction = true;  
  }
}