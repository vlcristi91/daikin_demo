#pragma once

#include "AcControllerState.h"

class AcControllerInput;
class AcControllerOutput;

class AcController
{
public:
	AcController(const AcControllerInput& input, AcControllerOutput& output);

	AcControllerState* getCurrentState() const { return _currentState; }
	//i/o are not members so we can inject mock classes easily.
	void cycle();
	void setState(AcControllerState& newState);

private:
	AcControllerState* _currentState;
    const AcControllerInput& _input;
	AcControllerOutput& _output;
};