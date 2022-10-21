///////////////////////////////////////////////////////////////////////////////
/// @file     AcControllerStates.h
/// @ingroup  AcControllerStates
/// @author   Ausy Technologies
/// @date     21/10/2022
/// @brief    The AcControllerStates class declaration

/// @copyright Copyright (C) 2022
/// @copyright Ausy Technologies
/// @copyright All rights reserved
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcControllerState.h"

class AcController;

class AcControllerOff : public AcControllerState
{
public:
	void enter(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override;
	void cycle(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override;
	void exit(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override {}
	static AcControllerState &getInstance();

private:
	AcControllerOff() {}
	AcControllerOff(const AcControllerOff &other);
	AcControllerOff &operator=(const AcControllerOff &other);
};

class AcControllerHeating : public AcControllerState
{
public:
	void enter(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override;
	void cycle(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override;
	void exit(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override {}
	static AcControllerState &getInstance();

private:
	AcControllerHeating() = default;
	AcControllerHeating(const AcControllerHeating &other);
	AcControllerHeating &operator=(const AcControllerHeating &other);
};

class AcControllerCooling : public AcControllerState
{
public:
	void enter(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override;
	void cycle(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override;
	void exit(AcController *acController, const IAcControllerInput &input, IAcControllerOutput &output) override {}
	static AcControllerState &getInstance();

private:
	AcControllerCooling() = default;
	AcControllerCooling(const AcControllerCooling &other);
	AcControllerCooling &operator=(const AcControllerCooling &other);
};
