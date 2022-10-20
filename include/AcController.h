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