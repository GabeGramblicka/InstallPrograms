//------------------------------------------------------------------------------
//
// File Name:	System.h
// Author(s):	Miles Haley
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

#include <string>
//#include "Precompiled.h"

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------

class System // Abstract
{
public:
    // Inherited Systems should specify their own name in the member intializer list
    System(std::string name);
    virtual ~System() {};

    // Each system should have this:
    static System& GetInstance();
    

    virtual bool Init() { return true; }
    virtual void Update(float dt) = 0; // Update must always be overriden
    virtual void Render() const {} // Don't have to override; not all systems need to render
    virtual void Exit() {}

    std::string const& GetName();

private:
    const std::string _name;
};