#pragma once

// temperature represented by 100 factor to avoid using floats. ("centi Celsius"), meaning 1C = 100cC
using temp = int;

// strong type representing %
using percentage = int;

template <typename T>
temp celsiusToTemp(T temperature)
{
    return static_cast<temp>(temperature * 100.0F);
}