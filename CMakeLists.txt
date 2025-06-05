cmake_minimum_required(VERSION 3.31.6)
project(Paint LANGUAGES CXX RC)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

                                                    
target_include_directories(${PROJECT_NAME} PRIVATE 
    src 
    src/utilities 
    src/menu 
    src/artist 
    src/artist/line_artist 
    src/artist/line_artist/line_strats
    src/artist/polygon_scanline_artist 
    src/artist/ellipse_artist 
    src/artist/ellipse_artist/ellipse_strats 
    src/artist/circle_filling_artist 
    src/artist/flood_fill_artist 
    src/artist/flood_fill_artist/flood_fill_strats 
    src/artist/window_clipping_artist 
    src/artist/window_clipping_artist/square_window 
    src/artist/window_clipping_artist/rectangle_window
    src/artist/circle_artist
    src/artist/circle_artist/circle_strats
)                                                    

if (MINGW)
    target_compile_options(${PROJECT_NAME} PRIVATE -mwindows)
    target_link_options(${PROJECT_NAME} PRIVATE -mwindows)
endif ()