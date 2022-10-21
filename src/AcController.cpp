///////////////////////////////////////////////////////////////////////////////
/// @file     AcController.cpp
/// @ingroup  AcController
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcController class definition

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#include "AcController.h"
#include "AcControllerStates.h"

AcController::AcController(const IAcControllerInput &input, IAcControllerOutput &output)
	: _currentState(&AcControllerOff::getInstance()), _input(input), _output(output)
{
}

void AcController::cycle()
{
	_currentState->cycle(this, _input, _output);
}

void AcController::setState(AcControllerState &newState)
{
	_currentState->exit(this, _input, _output);
	_currentState = &newState;
	_currentState->enter(this, _input, _output);
}
