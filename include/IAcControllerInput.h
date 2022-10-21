///////////////////////////////////////////////////////////////////////////////
/// @file     IAcControllerInput.h
/// @ingroup  IAcControllerInput
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The IAcControllerInput class declaration

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "common.h"

class IAcControllerInput
{
public:
    virtual void cycle() = 0;
    virtual temp getInteriorTemperature() const = 0;
    virtual temp getDesiredTemperature() const = 0;
};
