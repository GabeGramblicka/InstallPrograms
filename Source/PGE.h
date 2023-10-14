//------------------------------------------------------------------------------
//
// File Name:	Graphics.h
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
// Using glm for math
#include <glfw/glfw3.h> // Using glfw for window handling

#include "PGEWindow.h"
#include "PGESystem.h"

typedef class Camera Camera;
typedef class Mesh Mesh;
typedef class Shader Shader;

typedef GLuint GraphicsID;


//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

namespace PGE
{
	// defines for blendmodes
	typedef enum
	{
		PGE_BM_NONE,        // No blending 
		PGE_BM_BLEND,       // Color values will be blended using alpha values (normal transparency)
		PGE_BM_ADD,         // Color values will be added together
		PGE_BM_MULTIPLY,    // Color values will be multiplied together
	} PGE_BlendMode;

	// If an error is detected it will assert through here
	void CheckError();

	// Clears the background for the next frame
	void ClearBackground();

	// Sets a new background color
	// Params:
	//     Color values
	void SetBackgroundColor(float r, float g, float b, float a);

	// Sets the blend mode for translucent objects
	// Params:
	//     mode - blendmode to choose 
	void SetBlendMode(PGE_BlendMode mode);
}