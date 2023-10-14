//------------------------------------------------------------------------------
//
// File Name:	App.h
// Author(s):	
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

#include "Stream.h"

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------

class App
{
public:
	App(String key, String choco, String winget, String type);

	static std::vector<App> GetApps();

	void Install();
	void Uninstall();
	static void Display(String title, String type);
	static void Read(Stream& file);

	String GetKey()    { return _key;     };
	String GetChoco()  { return _choco;   };
	String GetWinget() { return _winget;  };
	String GetType()   { return _type;    };
	bool* GetChecked() { return _checked; };

	void SetChecked(bool flag) { *_checked = flag; };

private:
	bool*  _checked;

	String _key;
	String _choco;
	String _winget;
	String _type;
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
