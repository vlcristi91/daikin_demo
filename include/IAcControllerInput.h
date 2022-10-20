#pragma once
#include "common.h"

class IAcControllerInput
{
public:
    virtual void cycle() = 0;
    virtual temp getInteriorTemperature() const = 0;
    virtual temp getDesiredTemperature() const = 0;
};