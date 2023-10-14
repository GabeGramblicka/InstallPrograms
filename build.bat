@echo off

REM Get the directory of the batch file
set batchDir=%~dp0

REM Set the path to MSBuild for Visual Studio 2019
set msbuildPath="C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe"

REM Set the path to your project file (.vcxproj, .sln, etc.)
set projectPath=%batchDir%dreadit.vcxproj

REM Get the current date in the format "mm-dd-yyyy"
for /f "tokens=2-4 delims=/ " %%a in ('date /t') do (
    set "month=%%a"
    set "day=%%b"
    set "year=%%c"
)

REM Create a folder name based on the current date
set folderName=build-%month%-%day%-%year%

REM Prompt the user for the desired platform (r for Release, d for Debug)
set /p platformChoice=Enter platform (r for Release, d for Debug): 

REM Check if the user chose Release or Debug and set the configuration accordingly
if /i "%platformChoice%"=="r" (
    set configuration=Release
) else if /i "%platformChoice%"=="d" (
    set configuration=Debug
) else (
    echo Invalid choice. Please enter "r" for Release or "d" for Debug.
    pause
    exit /b
)

REM Set the output directory for the build artifact (DreadItRelease.exe or DreadItDebug.exe)
set outputDir=%batchDir%x64\%configuration%\

REM Clean and build the project for the selected configuration
echo Building configuration: %configuration%
%msbuildPath% /p:Configuration=%configuration% /p:Platform=x64

REM Create the build folder
mkdir "%batchDir%Builds\%folderName%"

REM Copy the executable file to the build folder with the appropriate name
copy "%outputDir%DreadIt.exe" "%batchDir%Builds\%folderName%\DreadIt%configuration%.exe"

REM Check if the Data, Shaders, and Assets folders exist, and copy them to the build folder
if exist "%batchDir%Data" xcopy /s /i /y "%batchDir%Data" "%batchDir%Builds\%folderName%\Data"
if exist "%batchDir%Shaders" xcopy /s /i /y "%batchDir%Shaders" "%batchDir%Builds\%folderName%\Shaders"
if exist "%batchDir%Assets" xcopy /s /i /y "%batchDir%Assets" "%batchDir%Builds\%folderName%\Assets"
if exist "%batchDir%Source" xcopy /s /i /y "%batchDir%Source" "%batchDir%Builds\%folderName%\Source"

pause