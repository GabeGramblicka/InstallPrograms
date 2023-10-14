//------------------------------------------------------------------------------
//
// File Name:	PGESystem.h
// Author(s):	Gabe Gramblicka
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

#include "PGE.h"

namespace PGE
{
	namespace Systems
	{
		// Initialize the graphics system
		bool Init();

		// Shuts down the graphics system
		void Exit();

		// Disables triangles to be seen from behind
		void DisableCulling();

		// Load a helper platform for the graphics system
		bool LoadPlatformHelper();

		// Asks for an openGL version
		void SetVersion();

		// Gets the openGL version
		const char* GetVersion();

		// Turns on or off vsync
		// Params:
		//     value - code to set vsync on or off. 1 is on??
		void SetVsync(int value);
	}
}

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------


