//------------------------------------------------------------------------------
//
// File Name:	PGESystem.cpp
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

#include "stdinclude.h"
#include "PGESystem.h"

using namespace PGE;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

bool Systems::Init()
{
    return glfwInit();
}

void PGE::Systems::Exit()
{
    // Shut down glfw and OpenGL
    glfwTerminate();
}

void Systems::DisableCulling()
{
    glDisable(GL_CULL_FACE);
    PGE::CheckError();
}

bool Systems::LoadPlatformHelper()
{
    return true;
}

void Systems::SetVersion()
{
    // Request the OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Systems::SetVsync(int value)
{
    glfwSwapInterval(value);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

