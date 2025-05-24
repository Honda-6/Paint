cmake_minimum_required(VERSION 3.31.6)
project(Paint LANGUAGES CXX RC)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
        Paint.cpp
)
set(HEADERS
        Paint.h
        framework.h
        Resource.h
)
set(RESOURCES
        Paint.rc
)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32 _WINDOWS)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()