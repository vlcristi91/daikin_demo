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