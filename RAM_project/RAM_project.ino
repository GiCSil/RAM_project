//Room Access Management Challenge
//Author: Giovane Carvalho Silvério
//06/01/2023

//-- Definitions --
#define DOOR_ONE 7  // defines de output to open the door 1
#define DOOR_TWO 8  // defines de output to open the door 2
#define CLOSE_ONE 2 // defines de input to close the door 1
#define CLOSE_TWO 3 // defines de input to close the door 2
#define timeCounter 5 // defines the timer

//-- Includes --
#include <Arduino.h>
#include <TimerOne.h>
#include "MenuSerial.h"
#include "User.h"
#include "AccessEvent.h"


//-- Declarations of Objects and Aux Variables --
MenuSerial menu;
User user;
AccessEvent event;
char menuSelection;           // selects the menu function
bool stopInstruction = true;  // stop instruction
int time = timeCounter;
bool door1 = false;
bool door2 = false;

//-- Functions --
void TimerInterrupt()
{
  if (door1)
  {
    door1 = false;
    digitalWrite(DOOR_ONE, LOW);    
  }
  if (door2)
  {
    door2 = false;
    digitalWrite(DOOR_TWO, LOW);
  }
  Timer1.stop();
}

void interrupt1()
{
  digitalWrite(DOOR_ONE), LOW);
}

void interrup2()
{
  digitalWrite(DOOR_TWO), LOW);
}

void DoorClosed(int door)
{
  switch (door)
  {
  case '1':
  door1 = true;
  Timer1.initialize(5000000);
  break;
  case '2':
  door2 = true;
  Timer1.initialize(5000000);
  break;
  default:
  Timer1.stop();
  break;
  }
}

//-- Setup --
void setup()
{
  // setup of the serial com
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  // setup of the IO's
  pinMode(DOOR_ONE, OUTPUT);  // represents the door 1
  pinMode(DOOR_TWO, OUTPUT);  // represents the door 2
  pinMode(CLOSE_ONE, INPUT_PULLUP); // represents the close button of the door 1
  pinMode(CLOSE_TWO, INPUT_PULLUP); // represents the close button of the door 2

  // setup of the timer and interruption
  Timer1.attachInterrupt(TimerInterrupt());
  attachInterrupt(digitalPinToInterrupt(CLOSE_ONE), interrupt1, LOW);
  attachInterrupt(digitalPinToInterrupt(CLOSE_TWO), interrupt2, LOW);
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
      user.ReturnUserList();
      break;
      case '3':
      event.ReturnEventList();
      break;
      case '4':
      if(user.AccessDoorOne())
      {
        Serial.println("Access to door 1 granted!");
        digitalWrite(DOOR_ONE, HIGH); //opens door 1
        DoorClosed(1);
      } else
      {
       Serial.println("Access to door 1 denied!"); 
      }
      break;
      case '5':
      if(user.AccessDoorTwo())
      {
        Serial.println("Access to door 2 granted!");
        digitalWrite(DOOR_TWO, HIGH); // opens door 2
        DoorClosed(2);
      } else
      {
       Serial.println("Access to door 2 denied!"); 
      }
      break;
      default:
      Serial.println("The option selected does not exists. Try again.");
      break;
    }
    stopInstruction = true;  
  }
}