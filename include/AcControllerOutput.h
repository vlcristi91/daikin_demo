///////////////////////////////////////////////////////////////////////////////
/// @file     AcControllerOutput.h
/// @ingroup  AcControllerOutput
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcControllerOutput class declaration

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "IAcControllerOutput.h"
#include "common.h"

class AcControllerOutput : public IAcControllerOutput
{
public:
    AcControllerOutput();

    // int demand is a value betwwen -100 and 100 descibing the cooling or heating intensity required.
    // -100 being max cooling, 0 meaning off and 100 meaning max heating.
    void setCoolingHeatingDemand(percentage demand) override { _demand = demand; }
    void cycle() override;

private:
    percentage _demand;
};
