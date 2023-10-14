//------------------------------------------------------------------------------
//
// File Name:	Trace.h
// Author(s):	Gryphon McLaughlin
// Project:		Dreadit
// Course:      GAM200
//
// Copyright © 2023 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

#include <fstream>

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------
class Trace
{
private:
	static std::ofstream* _log;

public:
	// Initializes the log file and opens it for reading.
	// Returns false if file failed to open.
	static bool Init();

	// Appends the given message to the log file.
	// Params:
	//	message = message to be appended
	static void Message(const std::string &message);

	// Reveals the Log object for stream insertion operator
	static std::ofstream& Log();

	// Closes the log file
	static void Exit();

};


//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------