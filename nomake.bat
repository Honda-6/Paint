@echo off

REM [CONFIGURATION]

REM Compiler flags
set CXXFLAGS=-mwindows -std=c++17 -Isrc -Isrc/menu -Isrc/artist -Isrc/artist/line_artist

REM Output executable
set OUTPUT=build\Paint.exe



REM [BUILD PROCESS]

setlocal enabledelayedexpansion

if not exist build (
    mkdir build
)

set SOURCES=

for /r src %%f in (*.cpp) do (
    set SOURCES=!SOURCES! %%f
)

REM Compile with g++
g++ !SOURCES! %CXXFLAGS% -o %OUTPUT%

if errorlevel 1 (
    echo Build failed.
    pause
    exit /b 1
) else (
    echo Build succeeded.
    echo Running %OUTPUT% ...
    %OUTPUT%
)

endlocal
