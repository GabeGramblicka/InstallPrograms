//------------------------------------------------------------------------------
//
// File Name:	UISystem.cpp
// Author(s):	William Kuhne, Nicholas Brennan
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
#include "UISystem.h"

#include "App.h"
#include "Engine.h"
#include <glfw/glfw3.h>
#include <imGui.h>
#include <imgui_impl_glfw.h>	// Renderer
#include <imgui_impl_opengl3.h> // Platform
#include "WindowSystem.h"
#include <cstdlib>


//------------------------------------------------------------------------------
// Private Variables
//------------------------------------------------------------------------------

static UISystem instance;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

System& UISystem::GetInstance()
{
	return instance;
}

UISystem::UISystem() 
	: System("UISystem")
	, _showDemo(0)
	, _showDebug(true)
	, _installApp(0)
	, _install(0)
	, _uninstall(0)
	, _clear(0)
	, _allowHotkeyScene(0)
{
}

UISystem::~UISystem()
{
}

bool UISystem::Init()
{
	// Setup ImGui
	const char* glsl_version = "#version 330";

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	// Add any potential flags here, see documentation
	// for available flags
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	ImGui_ImplGlfw_InitForOpenGL(WindowSystem::GetWindow(), true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	Stream stream("Data/apps.json");
	App::Read(stream);
	return true;
}

void UISystem::Update(float dt)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	if (_showDebug)
	{
		ShowDebug(&_showDebug, dt);
	}
	else
	{
		WindowSystem::IsRunning = false;
	}

#ifdef _DEBUG
	if (_showDemo)
	{
		ImGui::ShowDemoWindow(&_showDemo);
	}
#endif
	if (_install)
	{
		for (auto app : App::GetApps())
		{
			if (*(app.GetChecked()) == true)
			{
				app.Find(1);
			}
		}
	}
	if (_uninstall)
	{
		for (auto app : App::GetApps())
		{
			if (*(app.GetChecked()) == true)
			{
				app.Find(0);
			}
		}
	}
	if (_clear)
	{
		for (auto& app : App::GetApps())
		{
			app.SetChecked(false);
		}
	}
}

void UISystem::Render() const
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO& io = ImGui::GetIO();

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}


void UISystem::Exit()
{
	// Shutdown ImGui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();

	ImGui::DestroyContext();
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

void UISystem::ShowDebug(bool* p_open, float dt)
{
	ImGui::Begin("Program Installer", p_open);
	ImGui::SetNextWindowSize(ImVec2(763, 539), ImGuiCond_Always);

#ifdef _DEBUG
	ImGui::SeparatorText("General Options");
	ImGui::Checkbox("Show Demo Window", &_showDemo);
	ImGui::SameLine();
#endif

	_install   = ImGui::Button("Install Selected Programs", ImVec2(200, 22));
	ImGui::SameLine();
	_uninstall = ImGui::Button("Uninstall Selected Programs", ImVec2(200, 22));
	ImGui::SameLine();
	_clear = ImGui::Button("Clear Checkboxes", ImVec2(120, 22));

	ImGui::StyleColorsCustom();

	ImGui::SeparatorText("Programs");
	
	App::Display("Browsers", "browsers");
	App::Display("Communication", "communication");
	App::Display("Development", "dev");
	App::Display("Games", "games");
	App::Display("Multimedia", "media");
	App::Display("Microsoft", "microsoft");
	App::Display("Utitlites", "utilities");

	ImGui::End();
}