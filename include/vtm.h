#ifdef ARDUINO
#include <Arduino.h>
#endif
#include <Preferences.h>
#include "esp_can.h"
#include "virtualTimer.h"
#include "LUT.h"

class VTM
{
public:
    void SendAllLUT();

    void ProcessUpdate(uint8_t lut_idx, uint8_t value_idx, int16_t x, int16_t y);

    void SaveToFlash(uint8_t lut_idx);

private:
    Preferences prefs;
    ESPCAN can_bus{};
    VirtualTimerGroup timer_group{};
    LUT luts{};

    MakeSignedCANSignal(float, 0, 8, 1, 0) lut_idx{};
    MakeSignedCANSignal(float, 16, 8, 1, 0) value_idx{};
    MakeSignedCANSignal(float, 32, 16, 1, 0) x{};
    MakeSignedCANSignal(float, 48, 16, 1, 0) y{};

    CANTXMessage<4> update_message{can_bus, 0x100, 6, 100, timer_group, lut_idx, value_idx, x, y};
};