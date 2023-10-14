//------------------------------------------------------------------------------
//
// File Name:	Trace.cpp
// Author(s):	Gryphon McLaughlin
// Project:     Dreadit
// Course:		GAM200
//
// Copyright © 2023 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------
#include "Precompiled.h"
#include "Trace.h"

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
bool Trace::Init()
{
	_log = new std::ofstream();
	_log->open("Trace.log");
	if (!_log->is_open())
	{
		return false;
	}
	return true;
}

void Trace::Message(const String& message)
{
	(*_log) << message << "\n";
}

std::ofstream& Trace::Log()
{
	if (_log == nullptr)
		Init();
	return *_log;
}

void Trace::Exit()
{
	_log->close();
	delete _log;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
// Define initial value of private variable _log
std::ofstream * Trace::_log = nullptr;

