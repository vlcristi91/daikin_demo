///////////////////////////////////////////////////////////////////////////////
/// @file     AcControllerState.h
/// @ingroup  AcControllerState
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcControllerState class declaration

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
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
