#include <iostream>
#include <map>
using namespace std;

#ifdef ARDUINO
#include <Arduino.h>
#endif

class LUT
{
public:
    void UpdateLUT(uint8_t lut_idx, uint8_t value_idx, int16_t x, int16_t y)
    {
        luts[lut_idx][value_idx] = std::make_pair(x, y);
    }

    // inverter temp-amp lookup table
    std::vector<std::pair<int16_t, int16_t>> italut;

    // motor temp-amp lookup table
    std::vector<std::pair<int16_t, int16_t>> mtalut;

    // motor rmp-amp lookup table
    std::vector<std::pair<int16_t, int16_t>> mralut;

    // throttle map (percentage to torque multiplier) lookup table
    std::vector<std::pair<int16_t, int16_t>> tmlut;

    // vector of all luts
    std::vector<std::vector<std::pair<int16_t, int16_t>>> luts = {italut, mtalut, mralut, tmlut};
};