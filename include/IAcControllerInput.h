#pragma once

class IAcControllerInput
{
public:
    virtual void cycle() = 0;
    virtual int getInteriorTemperature() const = 0;
    virtual int getDesiredTemperature() const = 0;
};