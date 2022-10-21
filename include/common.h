///////////////////////////////////////////////////////////////////////////////
/// @file     common.h
/// @ingroup  common
/// @author   Ausy Technologies
/// @date     21/10/2022

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#pragma once

// temperature represented by 100 factor to avoid using floats. ("centi Celsius"), meaning 1C = 100cC
using temp = int;

// strong type representing %
using percentage = int;

// constexpr so we can calculate in C dudring compile time
template <typename T>
constexpr temp celsiusToTempConstexpr(T temperature)
{
    return static_cast<temp>(temperature * 100.0F);
}

// same but can be used during runtime. 
template <typename T>
temp celsiusToTemp(T temperature)
{
    return static_cast<temp>(temperature * 100.0F);
}


constexpr percentage COOLING_HEATING_OFF = 0;
constexpr percentage MAX_COOLING = 100;
constexpr percentage MAX_HEATING = -100;
constexpr temp COOLING_HEATING_TOLERANCE = celsiusToTempConstexpr(1);
