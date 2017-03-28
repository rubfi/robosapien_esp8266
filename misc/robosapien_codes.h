/* Robosapien codes
 * Taken from:
 *      http://web.archive.org/web/20071023184157/http://www.andrew.cmu.edu/user/ebuehl/robosapien-lirc/lircd.conf
 *      http://www.aibohack.com/robosap/ir_codes.htm
 */

#ifndef ROBOSAPIEN_CODES_H_
#define ROBOSAPIEN_CODES_H_

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
#endif
