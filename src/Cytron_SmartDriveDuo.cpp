#include "Cytron_SmartDriveDuo.h"





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
