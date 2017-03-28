/* robosapien_serial_cmd: Sends to the Robosapien the commands received via serial interface
 * Requires:
 *      - IR Led to ESP8266 GPIO pin 0 (D3 in Wemos mini D1)
 *      - IRremoteESP8266.h modified to support Robosapien V1 (https://github.com/rubfi/IRremoteESP8266)
 * Commands:
 *      w : RIGHT_ARM_UP
 *      s : RIGHT_ARM_DOWN
 *      q : LEFT_ARM_UP
 *      a : LEFT_ARM_DOWN
 *
 *      u : WALK_FORWARD
 *      j : WALK_BACKWARD
 *      h : TURN_LEFT
 *      k : TURN_RIGHT
 *
 *      p : STOP
 */

#include <IRremoteESP8266.h>

/* Robosapien codes
 * Taken from:
 *      http://web.archive.org/web/20071023184157/http://www.andrew.cmu.edu/user/ebuehl/robosapien-lirc/lircd.conf
 *      http://www.aibohack.com/robosap/ir_codes.htm
 */

#define TURN_RIGHT  0x00
#define RIGHT_ARM_UP  0x02
#define RIGHT_ARM_OUT 0x04
#define TILT_BODY_RIGHT 0x06
#define RIGHT_ARM_DOWN  0x08
#define RIGHT_ARM_IN  0x0A
#define WALK_FORWARD  0x0C
#define WALK_BACKWARD 0x0E
#define TURN_LEFT 0x10
#define LEFT_ARM_UP 0x12
#define LEFT_ARM_OUT  0x14
#define TILT_BODY_LEFT  0x16
#define LEFT_ARM_DOWN 0x18
#define LEFT_ARM_IN 0x1A
#define STOP 0x1C

// programming commands - no shift
#define MASTER_COMMAND  0x20
#define PROGRAM_PLAY  0x22
#define RIGHT_PROGRAM 0x24
#define LEFT_PROGRAM  0x26
#define SONIC_PROGRAM 0x28

// green shift commands
#define RIGHT_STEP  0x40
#define RIGHT_THUMP 0x42
#define RIGHT_THROW 0x44
#define SLEEP   0x46
#define RIGHT_PICKUP  0x48
#define LEAN_BACKWARD 0x4A
#define FORWARD_STEP  0x4C
#define BACKWARD_STEP 0x4E
#define LEFT_STEP 0x50
#define LEFT_THUMP  0x52
#define LEFT_THROW  0x54
#define LISTEN  0x56
#define LEFT_PICKUP 0x58
#define LEAN_FORWARD  0x5A
#define RESET   0x5C

#define MASTER_EXECUTE  0x60
#define WAKEUP 0x62
#define RIGHT_EXECUTE 0x64
#define LEFT_EXECUTE  0x66
#define SONIC_EXECUTE 0x68

// orange shift commands
#define RIGHT_STRIKE3 0x80
#define RIGHT_SWEEP 0x82
#define BURP    0x84
#define RIGHT_STRIKE2 0x86
#define HIGH5   0x88
#define RIGHT_STRIKE1 0x8A
#define BULLDOZER 0x8C
#define FART    0x8E
#define LEFT_STRIKE3  0x90
#define LEFT_SWEEP  0x92
#define WHISTLE   0x94
#define LEFT_STRIKE2  0x96
#define TALKBACK  0x98
#define LEFT_STRIKE1  0x9A
#define ROAR    0x9C

#define DEMO_ALL  0xA0
#define POWER_OFF 0xA2
#define DEMO1   0xA4
#define DEMO2   0xA6
#define DANCE   0xA8

// # secret codes
#define QUIET_EXECUTE 0x30
#define FEET_SHUFFLE  0xEC
#define NOTHING   0xF6
#define RAISE_ARM 0xF8
#define KARATE_CHOP 0xAC


IRsend irsend(0); // IR led in GPIO-0

int serial_cmd_to_rs(char c)
{
  switch(c) {
      case 'w' :
        return int(RIGHT_ARM_UP);
      case 's' :
        return int(RIGHT_ARM_DOWN);
      case 'q' :
        return int(LEFT_ARM_UP);
      case 'a' :
        return int(LEFT_ARM_DOWN);
      case 'u' :
        return int(WALK_FORWARD);
      case 'h' :
        return int(TURN_LEFT);
      case 'j' :
        return int(WALK_BACKWARD);
      case 'k' :
        return int(TURN_RIGHT);
      case 'p' :
        return int(STOP);
      default :
        Serial.print("<< Got: Char: ");
        Serial.print(c);
        Serial.println(" | Invalid Command");
        return -1;
   }
   return -1;
}

void setup()
{
  irsend.begin();
  Serial.begin(9600);
  Serial.print("Robosapien> ");
}

char cmd;
int icmd;

void loop() {
  if (Serial.available() > 0)
  {
    cmd = Serial.read();
    icmd = serial_cmd_to_rs(cmd);

    if (icmd != -1)
    {
      Serial.print(">> Sending: Hex: ");
      Serial.print(icmd, HEX);
      Serial.print("| Dec: ");
      Serial.println(icmd);

      irsend.sendRobosapien(icmd);
    }
    Serial.print("Robosapien> ");
    delay(1000);
  }
}
