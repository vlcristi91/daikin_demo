#pragma once

#include "IAcControllerInput.h"

class AcControllerInput : public IAcControllerInput
{
public:

    AcControllerInput();

    void cycle() override;
    int getInteriorTemperature() const override { return _interiorTemp; }
    int getDesiredTemperature() const override { return _desiredTemp; }

private:
    void readInteriorTemp();
    void readDesiredTemp();

    int _interiorTemp; 
    int _desiredTemp;
};