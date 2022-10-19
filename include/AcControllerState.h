#pragma once

class AcController;

class AcControllerState 
{
public:
    virtual void enter(AcController* acController) = 0;
	virtual void cycle(AcController* acController) = 0;
	virtual void exit(AcController* acController) = 0;
	virtual ~AcControllerState() {}
};