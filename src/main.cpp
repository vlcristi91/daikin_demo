///////////////////////////////////////////////////////////////////////////////
/// @file     main.cpp
/// @author   Ausy Technologies
/// @date     21/10/2022

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "AcController.h"
#include "AcControllerInput.h"
#include "AcControllerOutput.h"

#include <unistd.h>

int main()
{
    AcControllerInput input;
    AcControllerOutput output;
    AcController acController(input, output);

    while (true)
    {
        input.cycle();
        acController.cycle();
        output.cycle();

        // cycle time is 1 seconds
        constexpr useconds_t CYCLE_TIME_U_SEC = 1000000U;
        usleep(CYCLE_TIME_U_SEC);
    }

    return 0;
}
