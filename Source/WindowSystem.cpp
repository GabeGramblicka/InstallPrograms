//------------------------------------------------------------------------------
//
// File Name:	WindowSystem.cpp
// Author(s):	Gabe Gramblicka, Nick Brennan
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
#include "WindowSystem.h"

#include <Windows.h>
#include <iostream>

#include "PGE.h"

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

// Initialize static variables
GLFWwindow* WindowSystem::windowHandle = nullptr;
GLFWmonitor* WindowSystem::monitorHandle = nullptr;
bool WindowSystem::IsRunning = true;

// Create an instance of a window system
static WindowSystem instance;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

WindowSystem::WindowSystem()
    : System("WindowSystem")
{
}

System& WindowSystem::GetInstance()
{
    return instance;
}

bool WindowSystem::DoesWindowExist()
{
    return !glfwWindowShouldClose(windowHandle);
}

GLFWwindow* WindowSystem::GetWindow()
{
    if (windowHandle)
    {
        return windowHandle;
    }
    return nullptr;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

bool WindowSystem::Init()
{
    if (!PGE::Systems::Init())
    {
        return false;
    }

    PGE::Systems::SetVersion();

    const int width = 100, height = 100;

    // Create the window using the window size variables and our window title
    windowHandle = PGE::Window::Create(width, height, "Dread It", monitorHandle, nullptr);

    // If we failed to create the window, quit
    if (!windowHandle)
    {
        return false;
    }

    PGE::Window::MakeContextCurrent(windowHandle);
    // The minimum number of screen updates to wait before swapping buffers
    // This could be used for vsync etc., but we are setting it to 1 so it doesn't wait
    PGE::Systems::SetVsync(0);

    PGE::Systems::LoadPlatformHelper();

    // Set the background color
    PGE::SetBackgroundColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Disable culling (triangles seen from behind will be drawn)
    PGE::Systems::DisableCulling();

    PGE::Window::ResizeViewport(windowHandle, width, height);

    return true;
}

void WindowSystem::Update(float dt)
{
    PGE::Window::UpdateFrameControl(windowHandle);
    if (!DoesWindowExist())
    {
        IsRunning = false;
    }
}

void WindowSystem::Render() const
{
    PGE::ClearBackground();
}

void WindowSystem::Exit()
{
    PGE::Window::Close(windowHandle);
    PGE::Systems::Exit();
}

//----------------------------------------------------------------------------//
// OpenGL Example used in this file                                           //
//----------------------------------------------------------------------------//