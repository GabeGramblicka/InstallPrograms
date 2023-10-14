//------------------------------------------------------------------------------
//
// File Name:	PGEWindow.cpp
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
#include "PGEWindow.h"

#include "Trace.h"

using namespace PGE;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Window::Close(WindowHandle* handle)
{
    // Close the window
    glfwDestroyWindow(handle);
}

WindowHandle* Window::Create(int width, int height, String title, MonitorHandle* monitor, WindowHandle* window)
{
    WindowHandle* newWindow = nullptr;

    NULLIFY_PARAMETER(monitor);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    newWindow = glfwCreateWindow(width, height, "Dread It", monitor, window);

    if (newWindow == nullptr)
    {
        Trace::Message("PlatformSystemInit Error: The Pillar Graphics Engine could not be initialized!");
        return nullptr;
    }
    return newWindow;
}

void Window::CreateViewport(int width, int height)
{
    // Create the viewport at the specified size
    glViewport(0, 0, width, height);
    PGE::CheckError();
}

GLFWmonitor* PGE::Window::GetPrimaryMonitor()
{
    return glfwGetPrimaryMonitor();
}

void Window::MakeContextCurrent(WindowHandle* GLFWwindow)
{
    // Make this window's OpenGL context the current one
    glfwMakeContextCurrent(GLFWwindow);
}

void Window::ResizeViewport(WindowHandle* handle, int width, int height)
{
    //// Call our function to set up the viewport
    //Camera::CameraResizeViewport(handle, width, height);
    //
    //// Set this function to be called again whenever the window size changes
    //glfwSetFramebufferSizeCallback(handle, Camera::CameraResizeViewport);
    //// returns true if no short circuits are hit
}

void Window::UpdateFrameControl(WindowHandle* handle)
{
    // Handle the window events
    glfwPollEvents();

    int width = 100;
    int height = 100;

    // Swap the buffers to display everything from the current loop on the screen
    glfwSwapBuffers(handle);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

