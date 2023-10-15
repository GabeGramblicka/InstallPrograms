//------------------------------------------------------------------------------
//
// File Name:	UISystem.h
// Author(s):	William Kuhne and Nicholas Brennan
// Project:		Dreadit
// Course:      GAM200
//
// Copyright © 2023 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once


#include <vector>
#include <string.h>
#include <imgui.h>
#include "System.h"
#include "Stream.h"
#include <Windows.h>

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------

class UISystem : public System
{
public:
	static System& GetInstance();

	UISystem();
	~UISystem();

	bool Init() override;
	void Update(float dt) override;
	void Render() const override;
	void Exit() override;

private:

	bool _showDemo;
	bool _showDebug;
	bool _installApp;
	bool _install;
	bool _uninstall;
	bool _clear;
	bool _explorer;
	bool _allowHotkeyScene;

	void ShowDebug(bool* p_open, float dt);
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
