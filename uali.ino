/*
Receive data from a HM-10 Bluettoth device using a software serial connection.
The hardware serial connection is currently used for debugging.
*/

#include <SoftwareSerial.h>


SoftwareSerial BTserial(2, 3);


#define PIN_LEFT     7
#define PIN_FORWARD  8
#define PIN_RIGHT    9
 
typedef enum {
  UALI_CMD_LEFT = 100,
  UALI_CMD_RIGHT = 111,
  UALI_CMD_FORWARD = 122
} uali_commands_t;
 
void setup() 
{
  Serial.begin(9600);
  BTserial.begin(9600);
  
  pinMode(PIN_LEFT, OUTPUT); 
  pinMode(PIN_RIGHT, OUTPUT); 
  pinMode(PIN_FORWARD, OUTPUT); 
}
 
void loop()
{
 
  int c;
  
  if (BTserial.available()) {
    c = BTserial.read();
    switch(c) {
      case UALI_CMD_LEFT :
        Serial.println("LEFT");
        digitalWrite(PIN_LEFT, HIGH);
      break;
      case UALI_CMD_RIGHT:
        Serial.println("RIGHT");
        digitalWrite(PIN_RIGHT, HIGH);
      break;
      case UALI_CMD_FORWARD:
        Serial.println("FORWARD");
        digitalWrite(PIN_FORWARD, HIGH);
      break;
      default:
      break;
    }
  }
 
}
