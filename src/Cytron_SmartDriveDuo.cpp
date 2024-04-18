#include "Cytron_SmartDriveDuo.h"

/*
Cytron_SmartDriveDuo::Cytron_SmartDriveDuo(int mode, int rc1Pin, int rc2Pin)
{
  _mode = mode;
  _rc1Pin = rc1Pin;
  _rc2Pin = rc2Pin;

  pinMode(_rc1Pin, OUTPUT);
  pinMode(_rc2Pin, OUTPUT);
}
*/

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

boolean hardwareSerial;
Cytron_SmartDriveDuo::Cytron_SmartDriveDuo(int mode, int txPin, uint32_t baudrate)
{
  _mode = mode;
  _txPin = txPin;

  if (_txPin == 1) {
    hardwareSerial = true;
    Serial.begin(baudrate);
    while (!Serial);
  }
  else {
    hardwareSerial = false;
    pinMode(_txPin, OUTPUT);
    MDDSSerial = new SoftwareSerial(_txPin, _rxPin);  // Reversed tx and rx for SoftwareSerial
    MDDSSerial->begin(baudrate);
  }
}

Cytron_SmartDriveDuo::Cytron_SmartDriveDuo(int mode, int txPin, int boardId, uint32_t baudrate)
{
  _mode = mode;
  _txPin = txPin;
  _boardId = boardId;

  if (_txPin == 1) {
    hardwareSerial = true;
    Serial.begin(baudrate);
    while (!Serial);
  }
  else {
    hardwareSerial = false;
    pinMode(_txPin, OUTPUT);
    MDDSSerial = new SoftwareSerial(_txPin, _rxPin);  // Reversed tx and rx for SoftwareSerial
    MDDSSerial->begin(baudrate);
  }
}

void Cytron_SmartDriveDuo::initialByte(uint8_t dummyByte)
{
  if (hardwareSerial == true) {
    Serial.write(dummyByte);
  }
  else {
    MDDSSerial->write(dummyByte);
  }
}

void Cytron_SmartDriveDuo::control(signed int motorLSpeed, signed int motorRSpeed)
{
  switch (_mode) {
    case RC_MCU:
      // ... (no changes here)

    case PWM_INDEPENDENT:
      // ... (no changes here)

    case SERIAL_SIMPLIFIED:
      // ... (no changes here)

    case SERIAL_PACKETIZED:
      // ... (no changes here)

    default:
      break;
  }
}
