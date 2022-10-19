#include "AcControllerOutput.h"

#include <iostream>

AcControllerOutput::AcControllerOutput() : _demand(0) {}

void AcControllerOutput::cycle()
{
    //write demand to network for now just print it

    std::cout << "cooling heating demand is " << _demand << std::endl;
}
