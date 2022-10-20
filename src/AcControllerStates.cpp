#include "AcControllerStates.h"
#include "AcController.h"
#include "IAcControllerInput.h"
#include "IAcControllerOutput.h"
#include "common.h"

#include <iostream>
#include <array>
#include <algorithm>

AcControllerState &AcControllerOff::getInstance()
{
    static AcControllerOff singleton;
    return singleton;
}

AcControllerState &AcControllerCooling::getInstance()
{
    static AcControllerCooling singleton;
    return singleton;
}

AcControllerState &AcControllerHeating::getInstance()
{
    static AcControllerHeating singleton;
    return singleton;
}

namespace
{
    const temp COOLING_HEATING_TOLERANCE = celsiusToTemp(1);
    constexpr percentage COOLING_HEATING_OFF = 0;
    constexpr percentage MAX_COOLING = 100;
    constexpr percentage MAX_HEATING = -100;

    temp getTempDelta(const IAcControllerInput &input)
    {
        return input.getDesiredTemperature() - input.getInteriorTemperature();
    }

    percentage calculateCoolingHeatingDemand(temp tempDelta)
    {
        // steps in intensity
        std::array<int, 5> coolingHeatingIntensity{0, 25, 50, 75, 100};
        // steps in temperature, for every degree C difference we increase the intensity by 25%
        std::array<int, 5> tempDeltas{0, 100, 200, 300, 400};
        const auto elem_it = std::find_if(
            tempDeltas.begin(), tempDeltas.end(),
            [tempDelta](const int &x)
            { return abs(tempDelta) <= x; });

        const int elem_idx = std::distance(tempDeltas.begin(), elem_it) - 1;

        int coolingDemand = 0;

        if (elem_idx < coolingHeatingIntensity.size() - 1)
        {
            float x0 = tempDeltas[elem_idx];
            float x1 = tempDeltas[elem_idx + 1];
            float y0 = coolingHeatingIntensity[elem_idx];
            float y1 = coolingHeatingIntensity[elem_idx + 1];

            coolingDemand = y0 + ((y1 - y0) / (x1 - x0)) * (abs(tempDelta) - x0);
        }
        else
        {
            // next if statement switches to cooling if needed.
            coolingDemand = 100;
        }

        if (tempDelta < 0)
        {
            coolingDemand = -coolingDemand;
        }

        return coolingDemand;
    }
}

void AcControllerOff::cycle(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output)
{
    std::cout << "In state off" << std::endl;

    const auto delta = getTempDelta(input);

    if (delta < -COOLING_HEATING_TOLERANCE)
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
        output.setCoolingHeatingDemand(COOLING_HEATING_OFF);
    }
}

void AcControllerOff::enter(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output)
{
}

void AcControllerHeating::cycle(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output)
{
    std::cout << "in state heating" << std::endl;

    const auto delta = getTempDelta(input);

    // if we reach the desired temperature go to state off
    if (delta <= 0)
    {
        acController->setState(AcControllerOff::getInstance());
    }
    else
    {
        const int coolingHeatingDemand = calculateCoolingHeatingDemand(delta);
        std::cout << coolingHeatingDemand;
        output.setCoolingHeatingDemand(coolingHeatingDemand);
    }
}

void AcControllerHeating::enter(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output)
{
}

void AcControllerCooling::cycle(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output)
{
    std::cout << "in state cooling" << std::endl;
    const auto delta = getTempDelta(input);

    // cool enough turn off.
    if (delta >= 0)
    {
        acController->setState(AcControllerOff::getInstance());
    }
    else
    {
        const int coolingHeatingDemand = calculateCoolingHeatingDemand(delta);
        output.setCoolingHeatingDemand(coolingHeatingDemand);
    }
}

void AcControllerCooling::enter(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output)
{
}
