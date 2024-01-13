#ifdef ARDUINO
#include <Arduino.h>
#endif
#include "vtm.h"

void VTM::SaveToFlash(uint8_t lut_idx)
{
    const char *bytes = reinterpret_cast<const char *>(VTM::luts.luts[lut_idx].data());
    size_t size = sizeof(VTM::luts.luts[lut_idx]);
    const char *key = ("LUT" + std::to_string(lut_idx)).c_str();

    prefs.putBytes(key, bytes, size);
}

void VTM::SendAllLUT()
{
    // send all LUTs to client over CAN
}

void VTM::ProcessUpdate(uint8_t li, uint8_t vi, int16_t first, int16_t second)
{
    // send update to client over CAN
    lut_idx = li;
    value_idx = vi;
    x = first;
    y = second;

    // update LUT
    VTM::luts.UpdateLUT(lut_idx, value_idx, x, y);
}
