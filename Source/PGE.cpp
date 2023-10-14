//------------------------------------------------------------------------------
//
// File Name:	OpenGL.cpp
// Author(s):	Gabe Gramblicka
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
#include "PGE.h"

#include <cassert>
#include "Trace.h"
//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void PGE::CheckError()
{
    // Get the current error value
    GLenum error = glGetError();
    // Check if there is an error
    if (error != GL_NO_ERROR)
    {
        // Print the error value to the console
        std::cout << "Error: " << error << std::endl;
        // Use assert to stop the program so we can see what is happening
        assert(false);
    }
}

void PGE::ClearBackground()
{
    // Clear the background
    glClear(GL_COLOR_BUFFER_BIT);
    PGE::CheckError();
}

void PGE::SetBackgroundColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    PGE::CheckError();
}

void PGE::SetBlendMode(PGE_BlendMode mode)
{
    // Enable blending for normal transparency
    switch (mode)
    {
    case PGE_BM_NONE:
        glDisable(GL_BLEND);
        break;

    case PGE_BM_BLEND:
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        break;

    case PGE_BM_ADD:
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE);
        break;

    case PGE_BM_MULTIPLY:
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
        break;

    default:
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        break;

    }
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

//----------------------------------------------------------------------------//
// OpenGL Example used in this file                                           //
//----------------------------------------------------------------------------//
