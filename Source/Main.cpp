//------------------------------------------------------------------------------
//
// File Name:	Main.cpp
// Author(s):	
// Project:     Dreadit
// Course:		GAM200
//
// Copyright © 2023 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "Precompiled.h"

#include <Windows.h>
#include "Engine.h"
#include "Time.h"
#include "Trace.h"

//systems
#include "WindowSystem.h"
#include "UISystem.h"


int WINAPI wWinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE prevInstance, _In_ PWSTR pCmdLine, _In_ int cmdShow)
{
    UNREFERENCED_PARAMETER(prevInstance);
    UNREFERENCED_PARAMETER(pCmdLine);
    UNREFERENCED_PARAMETER(instance);
    UNREFERENCED_PARAMETER(cmdShow);

    // Creating engine variable
    Engine engine;

    //--------------------------------------------------------------------------
    // Add all systems to the engine framework.
    //--------------------------------------------------------------------------

    //NOTE: the order in which these systems are added is the order in which they will be updated
    engine.AddSystem(WindowSystem::GetInstance());
    engine.AddSystem(UISystem::GetInstance()); // Cheat system needs to come after Scene, or else objects will draw over ImGui

    // Initialize the trace module
    Trace::Init();

    if (!engine.Init())
    {
        Trace::Exit();
    }

    float dt = 0.0f;

    //--------------------------------------------------------------------------
    // MAIN LOOP:
    //--------------------------------------------------------------------------

    while (WindowSystem::IsRunning)
    {
        // Update the current frame.
        engine.Update(dt);
        
        // Render the current frame.
        engine.Render();
    }

    // Shutdown the game engine.
    engine.Exit();

    // Close the trace file
    Trace::Exit();
    return 0;
}