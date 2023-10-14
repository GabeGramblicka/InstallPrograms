//------------------------------------------------------------------------------
//
// File Name:	Engine.cpp
// Author(s):	Gryphon McLaughlin, Miles Haley
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
#include "Engine.h"
#include "System.h"

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

Engine::Engine() 
    : _systemList()
{
}

void Engine::AddSystem(System& system)
{
    _systemList.push_back(&system);
    //_systemContainer[_systemCount++] = &system;
}

bool Engine::Init()
{
    for (auto it = _systemList.begin(); it != _systemList.end(); ++it)
    {
        bool success = (*it)->Init();
        if (!success)
        {
            return false;
        }
    }
    return true;
}

void Engine::Update(float dt)
{
    for (auto it = _systemList.begin(); it != _systemList.end(); ++it)
    {
        (*it)->Update(dt);
    }
}

void Engine::Render() const
{
    // Start drawing here
    for (auto it = _systemList.begin(); it != _systemList.end(); ++it)
    {
        (*it)->Render();
    }
    // Finish drawing here
}

void Engine::Exit()
{
    // Order is reversed
    for (auto it = _systemList.rbegin(); it != _systemList.rend(); ++it)
    {
        (*it)->Exit();
    }
    _systemList.clear();
    //for (unsigned i = 0; i < _systemCount; i++)
    //{
    //    // Order is reversed
    //    _systemContainer[_systemCount - i]->Exit();
    //}
}



