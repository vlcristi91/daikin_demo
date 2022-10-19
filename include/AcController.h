#pragma once

#include "AcControllerState.h"

class AcController
{
public:
	AcController();

	 AcControllerState* getCurrentState() const { return _currentState; }
	void cycle();
	void setState(AcControllerState& newState);

private:
	AcControllerState* _currentState;
};