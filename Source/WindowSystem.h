//------------------------------------------------------------------------------
//
// File Name:	WindowSystem.h
// Author(s):	Gabe Gramblicka, Nick Brennan
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

#include "System.h"

struct GLFWwindow;
struct GLFWmonitor;

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------

class WindowSystem : public System
{
private:
	// Stores the handle to the window
	static GLFWwindow* windowHandle;

	// Stores the handle for the monitor
	static GLFWmonitor* monitorHandle;

	// system base class overrides
	bool Init() override;
	void Update(float dt) override;
	void Render() const override;
	void Exit() override;

public:
	// Default constructor
	WindowSystem();

	// Returns the instance of the system
	static System& GetInstance();

	// Determines if the window has been closed by the x
	static bool DoesWindowExist();

	static GLFWwindow* GetWindow();

	static bool IsRunning;
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

