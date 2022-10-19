#include "AcControllerStates.h"
#include "AcController.h"
#include "AcControllerInput.h"
#include "AcControllerOutput.h"

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

namespace
{
    constexpr int COOLING_HEATING_TOLERANCE = 1;
    constexpr int COOLING_HEATING_OFF = 0;
    constexpr int MAX_COOLING = 100;
    constexpr int MAX_HEATING = -100;

    int getTempDelta(const AcControllerInput& input)
    {
        return input.getDesiredTemperature() - input.getInteriorTemperature();
    }
}


void AcControllerOff::cycle(AcController* acController, const AcControllerInput& input, AcControllerOutput& output)
{
    std::cout << "In state off" << std::endl;

    const auto delta = getTempDelta(input);

    if (delta < COOLING_HEATING_TOLERANCE)
    {
        acController->setState(AcControllerCooling::getInstance());
    }
    else if (delta > COOLING_HEATING_TOLERANCE)
    {
        acController->setState(AcControllerHeating::getInstance());
    }
    else
    {
        // no cooling or heating needed
    }

}

void AcControllerOff::enter(AcController* acController, const AcControllerInput& input, AcControllerOutput& output)
{
    output.setCoolingHeatingDemand(COOLING_HEATING_OFF);
}

void AcControllerHeating::cycle(AcController* acController, const AcControllerInput& input, AcControllerOutput& output)
{
    std::cout << "in state heating" << std::endl;
    
    const auto delta = getTempDelta(input);

    // if we reach the desired temperature go to state off
    if ((delta >= -COOLING_HEATING_TOLERANCE) && (delta < 0))
    {
        acController->setState(AcControllerOff::getInstance());
    }

    acController->setState(AcControllerCooling::getInstance());
}

void AcControllerHeating::enter(AcController* acController, const AcControllerInput& input, AcControllerOutput& output)
{
    output.setCoolingHeatingDemand(MAX_HEATING);
}

void AcControllerCooling::cycle(AcController* acController, const AcControllerInput& input, AcControllerOutput& output)
{
    std::cout << "in state cooling" << std::endl;
    const auto delta = getTempDelta(input);

    // cool enough turn off.
    if (delta >= 0)
    {
        acController->setState(AcControllerOff::getInstance());
    }
}

void AcControllerCooling::enter(AcController* acController, const AcControllerInput& input, AcControllerOutput& output)
{
    output.setCoolingHeatingDemand(MAX_COOLING);
}


