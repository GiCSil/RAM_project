#include <Arduino.h>

#define MAX_USERS 50

class User
{
  private:  
  int users PROGMEM = 0;
  const char adminPassword[] PROGMEM = "0000";
  String username[MAX_USERS];
  String password[MAX_USERS];
  public:
  void AddUser();
  void ReturnUserList();
  bool AccessDoorOne();
  bool AccessDoorTwo()
}