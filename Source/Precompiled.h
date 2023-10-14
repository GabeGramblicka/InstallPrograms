//------------------------------------------------------------------------------
//
// File Name:	Precompiled.h
// Author(s):	WIlliam Kuhne
// Project:		Dreadit
// Course:      GAM200
//
// Copyright © 2023 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

#pragma warning(push)
#pragma warning(disable : 4001)


//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

//#include <Windows.h> <- this is a large file, should be included as-needed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>
#include <map>

//#define String std::string
using String = std::string;

#define NULLIFY_PARAMETER(parameter) (parameter);

//------------------------------------------------------------------------------
// Classes:
//------------------------------------------------------------------------------