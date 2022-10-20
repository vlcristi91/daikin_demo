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
