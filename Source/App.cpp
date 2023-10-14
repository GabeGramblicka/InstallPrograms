//-----------------------------------------------------------------------------
//
// File Name:	App.cpp
// Author(s):	
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
#include "App.h"

#include "UISystem.h"
#include <imgui.h>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

static std::vector<App> apps;

App::App(String key, String choco, String winget, String type)
	: _key(key)
	, _choco(choco)
	, _winget(winget)
	, _checked(new bool)
	, _type(type)
{
	*_checked = false;
}

std::vector<App> App::GetApps()
{
	return apps;
}

void App::Read(Stream& file)
{
	try {
		json jsonData = file.Get();

		for (const auto& item : jsonData.items()) {
			const String key = item.key();
			const String choco = item.value()["choco"];
			const String winget = item.value()["winget"];
			const String type = item.value()["type"];

			App app(key, choco, winget, type);
			apps.push_back(app);
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error parsing JSON: " << e.what() << std::endl;
		return;
	}
}

void App::Install()
{
	int err = 0;
	if (_winget == "na")
	{
		err = -1;
	}

	// first try winget
	_winget.insert(0, "winget install ");
	std::cout << "";
	err = std::system(_winget.c_str());

	if (err != 1)
	{
		if (_choco == "na")
		{
			err = -1;
		}
		// then try choco
		_choco.insert(0, "choco install ");
		std::cout << "";
		int err = std::system(_choco.c_str());

		if (err != 1 && err != 0)
		{
			std::cerr << "Installation failed\n";
		}
	}
}

void App::Uninstall()
{
	int err = 0;
	if (_winget == "na")
	{
		err = -1;
	}

	// first try winget
	_winget.insert(0, "winget uninstall ");
	std::cout << "";
	err = std::system(_winget.c_str());

	if (err != 1)
	{
		if (_choco == "na")
		{
			err = -1;
		}
		// then try choco
		_choco.insert(0, "choco uninstall ");
		std::cout << "";
		int err = std::system(_choco.c_str());

		if (err != 1)
		{
			std::cerr << "Installation failed\n";
		}
	}
}

void App::Display(String title, String type)
{
	if (ImGui::CollapsingHeader(title.c_str()))
	{
		for (auto& app : apps)
		{
			if (app.GetType() == type)
			{
				ImGui::Checkbox(app.GetKey().c_str(), app.GetChecked());
			}
		}
	}
}


//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

