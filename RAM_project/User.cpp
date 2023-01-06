#include "User.h"

void User::AddUser()
{
  Serial.println("Please, enter the new username:\n")
  while (Serial.available() > 0) {
    String user = Serial.readStringUntil('\n');
    break;
  }
  username[users] = user[users];  // added the username to the list of users

  Serial.println("Please, enter the 4 digit password:\n")
  while (Serial.available() > 0) {
    String user = Serial.readStringUntil('\n');
    break;
  }
  password[users] = user[users];  // added the respective password (without the needed checkings, I know)

  users++;  // new user

  if(users>=50)
  {
    users--;  // risks breaking the integrity of data but doesnt overflow
  }
}

void User::ReturnUserList()
{
  for(int i = 0; i <= users; i++){
    Serial.println(username[i]);
  }
}

void User::AccessDoorOne()
{
  
}

void User::AccessDoorTwo()
{
  
}