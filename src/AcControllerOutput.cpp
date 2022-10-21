///////////////////////////////////////////////////////////////////////////////
/// @file     AcControllerOutput.cpp
/// @ingroup  AcControllerOutput
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcControllerOutput class definition

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "AcControllerOutput.h"

#include <iostream>

AcControllerOutput::AcControllerOutput() : _demand(0) {}

void AcControllerOutput::cycle()
{
    // write demand to network for now just print it

    std::cout << "cooling heating demand is " << _demand << std::endl;
}
