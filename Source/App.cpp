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

App::App(String key, String choco, String winget, String installer, String uninstaller, String type)
	: _key(key)
	, _choco(choco)
	, _winget(winget)
	, _checked(new bool)
	, _type(type)
	, _installer(installer)
	, _uninstaller(uninstaller)
{
	*_checked = false;
}

std::vector<App> App::GetApps()
{
	return apps;
}

void App::Read(Stream& file)
{
	try
	{
		json jsonData = file.Get();

		for (const auto& item : jsonData.items()) {
			const String key = item.key();
			const String choco = item.value()["choco"];
			const String winget = item.value()["winget"];
			const String type = item.value()["type"];
			const String installer = item.value()["installer"];
			const String uninstaller = item.value()["uninstaller"];

			App app(key, choco, winget, installer, uninstaller, type);
			apps.push_back(app);
		}
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Error parsing JSON: " << e.what() << std::endl;
		return;
	}
}

void App::Find(int _stall)
{
	String stall;
	_stall == 1 ? stall = "install " : stall = "uninstall ";

	int err = 0;
	if (_winget == "na")
	{
		err = -1;
	}
	else
	{
		// first try winget
		stall.insert(0, "winget ");
		_winget.insert(0, stall);
		std::cout << "";
		err = std::system(_winget.c_str());
	}

	if (err != 1 && err != 0)
	{
		if (_choco == "na")
		{
			err = -1;
		}
		else
		{
			// then try choco
			stall.erase(0, 7);
			stall.insert(0, "choco ");
			_choco.insert(0, stall);
			std::cout << "";
			int err = std::system(_choco.c_str());
		}

		if (err != 1 && err != 0)
		{
			if (_installer == "na")
			{
				std::cerr << "Installation failed\n";
			}
			else
			{
				std::cout << "";
				_installer.insert(0, ".\\Data\\Executables\\");
				_uninstaller.insert(0, ".\\Data\\Executables\\");
				if (_stall == 1)
				{
					err = std::system(_installer.c_str());
				}
				else
				{
					err = std::system(_uninstaller.c_str());
				}

				if (err != 1)
				{
					std::cerr << "Installation failed\n";
				}
			}
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

