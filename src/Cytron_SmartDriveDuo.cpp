#include "Cytron_SmartDriveDuo.h"

Cytron_SmartDriveDuo::Cytron_SmartDriveDuo(int mode, int in1Pin, int in2Pin, int an1Pin, int an2Pin)
{
  _mode = mode;
  _an1Pin = an1Pin;
  _an2Pin = an2Pin;
  _in1Pin = in1Pin;
  _in2Pin = in2Pin;
  
  pinMode(_an1Pin, OUTPUT);
  pinMode(_an2Pin, OUTPUT);
  pinMode(_in1Pin, OUTPUT);
  pinMode(_in2Pin, OUTPUT);
}

Cytron_SmartDriveDuo::Cytron_SmartDriveDuo(int mode, uint32_t baudrate)
{
  _mode = mode;
  Serial.begin(baudrate);
  while (!Serial);
}

Cytron_SmartDriveDuo::Cytron_SmartDriveDuo(int mode, int boardId, uint32_t baudrate)
{
  _mode = mode;
  _boardId = boardId;
  Serial.begin(baudrate);
  while (!Serial);
}

void Cytron_SmartDriveDuo::initialByte(uint8_t dummyByte)
{
  Serial.write(dummyByte);
}

void Cytron_SmartDriveDuo::control(signed int motorLSpeed, signed int motorRSpeed)
{
  switch (_mode) {
    case RC_MCU:
      // ... (same as before)
      break;

    case PWM_INDEPENDENT:
      // ... (same as before)
      break;

    case SERIAL_SIMPLIFIED:
      // ... (same as before)
      break;

    case SERIAL_PACKETIZED:
      // ... (same as before)
      break;

    default:
      break;
  }
}
