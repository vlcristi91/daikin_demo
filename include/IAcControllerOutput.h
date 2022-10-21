///////////////////////////////////////////////////////////////////////////////
/// @file     IAcControllerOutput.h
/// @ingroup  IAcControllerOutput
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The IAcControllerOutput class declaration

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "common.h"

class IAcControllerOutput
{
public:
    virtual void cycle() = 0;

    // int demand is a value betwwen -100 and 100 descibing the cooling or heating intensity required.
    // -100 being max cooling, 0 meaning off and 100 meaning max heating.
    virtual void setCoolingHeatingDemand(percentage demand) = 0;
};
