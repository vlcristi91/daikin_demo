#include "AcController.h"
#include "AcControllerStates.h"
AcController::AcController() : _currentState(&AcControllerOff::getInstance())
{

}

void AcController::cycle()
{
    _currentState->cycle(this);
}

void AcController::setState(AcControllerState& newState)
{
	_currentState->exit(this);  
	_currentState = &newState; 
	_currentState->enter(this);
}