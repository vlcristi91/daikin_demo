#include "AcController.h"
#include "AcControllerStates.h"
AcController::AcController(const AcControllerInput& input, AcControllerOutput& output) 
	: _currentState(&AcControllerOff::getInstance())
	, _input(input)
	, _output(output)
{

}

void AcController::cycle()
{
    _currentState->cycle(this, _input, _output);
}

void AcController::setState(AcControllerState& newState)
{
	_currentState->exit(this, _input, _output);  
	_currentState = &newState; 
	_currentState->enter(this, _input, _output);
}