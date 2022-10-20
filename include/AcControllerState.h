#pragma once

class AcController;

class IAcControllerInput;
class IAcControllerOutput;

class AcControllerState
{
public:
	virtual void enter(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) = 0;
	virtual void cycle(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) = 0;
	virtual void exit(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) = 0;
	virtual ~AcControllerState() {}
};