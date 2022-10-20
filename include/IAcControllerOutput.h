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