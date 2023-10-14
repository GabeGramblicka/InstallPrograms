//------------------------------------------------------------------------------
//
// File Name:	StubSystem.cpp
// Author(s):	Miles Haley
// Project:     Dreadit
// Course:		GAM200
//
// Copyright � 2023 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Precompiled.h"
#include "StubSystem.h"

//------------------------------------------------------------------------------
// Instance:
//------------------------------------------------------------------------------

// Create the instance of the system
StubSystem instance;
System& StubSystem::GetInstance()
{
	return instance;
}

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

StubSystem::StubSystem()
	: System("StubSystem")
{
}

void StubSystem::Update(float dt) 
{
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------