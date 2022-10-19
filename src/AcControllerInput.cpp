#include "AcControllerInput.h"
#include <stdlib.h>
#include <iostream>

AcControllerInput::AcControllerInput() : _interiorTemp(20), _desiredTemp(23)
{
    
}

void AcControllerInput::cycle()
{
    readInteriorTemp();
    readDesiredTemp();

    std::cout << _interiorTemp << ";" << _desiredTemp << std::endl;
}


void AcControllerInput::readDesiredTemp()
{
    // for POC desired temp stays constant.
    _desiredTemp = 23;
}

void AcControllerInput::readInteriorTemp()
{
    _interiorTemp = rand() % 46;
}
