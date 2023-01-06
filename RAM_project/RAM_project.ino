//Room Access Management Challenge
//Author: Giovane Carvalho Silvério
//06/01/2023


void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // menu options
  Serial.println("1 - Register User");
  Serial.println("2 - List of Users");
  Serial.println("3 - List of Events");
  Serial.println("4 - Access Door 1");
  Serial.println("5 - Access Door 2");

  // if there's any serial available, read it:
  while (Serial.available() > 0) {

  }
}
