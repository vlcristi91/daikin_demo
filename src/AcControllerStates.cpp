#include "AcControllerStates.h"
#include "AcController.h"
#include <iostream>

AcControllerState& AcControllerOff::getInstance()
{
	static AcControllerOff singleton;
	return singleton;
}

AcControllerState& AcControllerCooling::getInstance()
{
	static AcControllerCooling singleton;
	return singleton;
}

AcControllerState& AcControllerHeating::getInstance()
{
	static AcControllerHeating singleton;
	return singleton;
}


void AcControllerOff::cycle(AcController* acController)
{
    std::cout << "In state off" << std::endl;
    acController->setState(AcControllerHeating::getInstance());
}

void AcControllerHeating::cycle(AcController* acController)
{
    std::cout << "in state heating" << std::endl;
    acController->setState(AcControllerCooling::getInstance());
}

void AcControllerCooling::cycle(AcController* acController)
{
    std::cout << "in state cooling" << std::endl;
    acController->setState(AcControllerOff::getInstance());
}

