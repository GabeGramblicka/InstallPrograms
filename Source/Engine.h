//------------------------------------------------------------------------------
//
// File Name:	Engine.h
// Author(s):	Miles Haley, Gryphon McLaughlin
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

#include <vector>
class System;

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------

class Engine
{
private:
    std::vector<System*> _systemList;
    //unsigned _systemCount; Will start at 0
public:
    Engine();

    void AddSystem(System& system);

    bool Init();
    void Update(float dt);
    void Render() const;
    void Exit();
};