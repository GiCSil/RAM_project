#include <Arduino.h>

#define MAX_USERS 10
#define MAX_EVENTS 10

class User
{
  private:  
    int users PROGMEM = 0;
    int events PROGMEM = 0;
    String adminPassword PROGMEM = {"0000"};
    String adminPasswords[MAX_USERS] PROGMEM = {"", "", "", "", "", "", "", "", "", ""};
    String username[MAX_USERS] PROGMEM = {"", "", "", "", "", "", "", "", "", ""};
    String password[MAX_USERS] PROGMEM = {"", "", "", "", "", "", "", "", "", ""};
    String eventsLog[2][MAX_EVENTS] PROGMEM = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
  public:
    User();
    ~User();    
    void AddUser();
    void ReturnUserList();
    bool AccessDoorOne();
    bool AccessDoorTwo();
    void ReturnEventList();
};