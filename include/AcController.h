///////////////////////////////////////////////////////////////////////////////
/// @file     AcController.h
/// @ingroup  AcController
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcController class declaration

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcControllerState.h"

class IAcControllerInput;
class IAcControllerOutput;

class AcController
{
public:
	AcController(const IAcControllerInput &input, IAcControllerOutput &output);

	AcControllerState *getCurrentState() const { return _currentState; }
	void cycle();
	void setState(AcControllerState &newState);

private:
	AcControllerState *_currentState;
	const IAcControllerInput &_input;
	IAcControllerOutput &_output;
};
