#include <Arduino.h>

class User
{
  private:
  int adminPassword=1234;
  public:
  void AddUser();
  void DeleteUser();
  void UserList();
  void AccessDoorOne();
  void AccessDoorTwo()
}