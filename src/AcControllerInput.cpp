///////////////////////////////////////////////////////////////////////////////
/// @file     AcControllerInput.cpp
/// @ingroup  AcControllerInput
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcControllerInput class definition

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "AcControllerInput.h"
#include <stdlib.h>
#include <iostream>

AcControllerInput::AcControllerInput() : _interiorTemp(2000), _desiredTemp(2300)
{
}

void AcControllerInput::cycle()
{
    readInteriorTemp();
    readDesiredTemp();
}

void AcControllerInput::readDesiredTemp()
{
    // for POC desired temp stays constant.
    _desiredTemp = 2300;
}

void AcControllerInput::readInteriorTemp()
{
    // for PoC set random interior temp between 18 and 30 C
    _interiorTemp = 1800 + rand() % 1200;
}
