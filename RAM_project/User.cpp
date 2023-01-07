#include "User.h"

void User::AddUser()
{
  String user;
  bool check;
  bool admin;

  Serial.println("Are you an admin user? y or n\n");
  while (Serial.available() > 0)
  {
    user = Serial.read;
    break;
  }
  if(user == 'y')
  {
    Serial.println("Type in the admin password:\n");
    while (Serial.available() > 0)
    {
      user = Serial.readStringUntil('\n');
      break;
    }
    if(user.equals(adminPassword))
    {
      check = true;
      admin = true;
    }
    else
    {
      Serial.println("Incorrect password. Registration denied.\n");
      check = false;
      admin = false;
    }
  } 
  else if(user =='n')
  {    
    check = true;
    admin = false;
  } 
  else 
  {
    Serial.println("Ilegal answer\n")
    check = false;
    admin = false;
  }

  if(check)
  {
    Serial.println("Please, enter the new username:\n")
    while (Serial.available() > 0)
    {
      user = Serial.readStringUntil('\n');
      break;
    }
    username[users] = user;  // added the username to the list of users

    Serial.println("Please, enter the 4 digit password:\n")
    while (Serial.available() > 0)
    {
      user = Serial.readStringUntil('\n');
      break;
    }
    if(admin)
    {
      adminPasswords[users] = user;
    }                                // added the respective password (without the needed checkings, I know)
    else
    {
      password[users] = user;
    }

    users++;  // new user

    if(users>=10)
    {
      users--;  // risks breaking the integrity of data but doesnt overflow
    }
  }
}

void User::ReturnUserList()
{
  for(int i = 0; i <= users; i++)
  {
    Serial.println(username[i]);
  }
}

bool User::AccessDoorOne()
{
  String passw;

  Serial.println("Please, enter your credencials 4 digit password:\n");
  while (Serial.available() > 0)
  {
    passw = Serial.readStringUntil('\n');
    break;
  }

  for(int i = 0; i <= users; i++)
  {
    if(password[i].equals(passw))
    {
      eventsLog[0][events] = username[i];
      eventsLog[1][events] = "1";

      events++;  // new event

      if(events>=10)
      {
        events--;  // risks breaking the integrity of data but doesnt overflow
      }

      return true;
    }
  }

  Serial.println("Access denied.\n")
  return false;
}

void User::AccessDoorTwo()
{
  String passw;

  Serial.println("Please, enter your credencials 4 digit password:\n");
  while (Serial.available() > 0)
  {
    passw = Serial.readStringUntil('\n');
    break;
  }

  for(int i = 0; i <= users; i++)
  {
    if(password[i].equals(passw))
    {
      eventsLog[0][events] = username[i];
      eventsLog[1][events] = "2";

      events++;  // new event

      if(events>=10)
      {
        events--;  // risks breaking the integrity of data but doesnt overflow
      }
      
      return true;
    }
  }

  Serial.println("Access denied.\n")
  
  return false;
}

void User::ReturnEventList()
{
  for(int i = 0; i <= 1; i++)
  {
    for(int j = 0; j <= events; j++)
    {
      Serial.println(eventsLog[i][j]);
    }
  }
}