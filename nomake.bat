@echo off

REM [CONFIGURATION]

REM Source files
set FILES=Paint.cpp NullArtist.cpp

REM Compiler flags
set CXXFLAGS=-mwindows -std=c++17

REM Output executable
set OUTPUT=build\Paint.exe



REM [BUILD PROCESS]

setlocal enabledelayedexpansion

if not exist build (
    mkdir build
)

set SOURCES=

for %%f in (%FILES%) do (
    set SOURCES=!SOURCES! src\%%f
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
