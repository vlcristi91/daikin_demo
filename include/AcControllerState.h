#pragma once

class AcController;

class AcControllerInput;
class AcControllerOutput;

class AcControllerState
{
public:
	virtual void enter(AcController *acController, const AcControllerInput &input, AcControllerOutput &output) = 0;
	virtual void cycle(AcController *acController, const AcControllerInput &input, AcControllerOutput &output) = 0;
	virtual void exit(AcController *acController, const AcControllerInput &input, AcControllerOutput &output) = 0;
	virtual ~AcControllerState() {}
};