@echo off

REM [CONFIGURATION]

REM Compiler flags

set CXXFLAGS=-mwindows -std=c++17 -Isrc -Isrc/utilities -Isrc/menu -Isrc/artist -Isrc/artist/line_artist -Isrc/artist/line_artist/line_strats -Isrc/artist/polygon_scanline_artist -Isrc/artist/ellipse_artist -Isrc/artist/ellipse_artist/ellipse_strats -Isrc/artist/circle_filling_artist -Isrc/artist/flood_fill_artist -Isrc/artist/flood_fill_artist/flood_fill_strats -Isrc/artist/window_clipping_artist -Isrc/artist/window_clipping_artist/square_window -Isrc/artist/window_clipping_artist/rectangle_window -Isrc/artist/circle_artist -Isrc/artist/circle_artist/circle_strats



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
