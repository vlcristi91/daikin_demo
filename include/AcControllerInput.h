///////////////////////////////////////////////////////////////////////////////
/// @file     AcControllerInput.h
/// @ingroup  AcControllerInput
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcControllerInput class declaration

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "IAcControllerInput.h"
#include "common.h"

class AcControllerInput : public IAcControllerInput
{
public:
    AcControllerInput();

    void cycle() override;
    temp getInteriorTemperature() const override { return _interiorTemp; }
    temp getDesiredTemperature() const override { return _desiredTemp; }

private:
    void readInteriorTemp();
    void readDesiredTemp();

    temp _interiorTemp;
    temp _desiredTemp;
};
