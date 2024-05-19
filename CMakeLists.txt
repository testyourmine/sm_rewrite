cmake_minimum_required(VERSION 3.21)

if ("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
    message(FATAL_ERROR "You are compiling in the source tree, you should not do that. Use -B to set the build directory")
endif()

project(sm
    VERSION 0.0.1
    DESCRIPTION "Super Metroid PC Port"
    HOMEPAGE_URL "https://github.com/snesrev/sm"
    LANGUAGES C)

include(GNUInstallDirs)

# Compiler Warnings
list(APPEND c_warnings
    "-fno-strict-aliasing")

list(APPEND msvc_warnings
    "/W3"
    "/wd4996")

# For installation later
set(ini_name "${PROJECT_SOURCE_DIR}/sm.ini")

# Dependencies
# ------------
# SDL
if (NINTENDO_SWITCH)
    # Force static on Switch, just because it's easier
    find_package(SDL2 REQUIRED COMPONENTS SDL2-static)
else()
    find_package(SDL2 REQUIRED COMPONENTS SDL2)
endif()

# Main Executable
# ---------------
add_executable(sm)
add_subdirectory(src)
add_subdirectory(third_party)

# Math library
find_library(MATHLIB m)

# Target properties
target_link_libraries(sm PRIVATE
    $<$<BOOL:${MATHLIB}>:m> SDL2::SDL2)

# This is for third_party
target_include_directories(sm PRIVATE ".")

set_target_properties(sm PROPERTIES C_STANDARD 11)

target_compile_options(sm PRIVATE $<IF:$<C_COMPILER_ID:MSVC>,${msvc_warnings},${c_warnings}>)

target_compile_definitions(sm PRIVATE
    $<$<NOT:$<C_COMPILER_ID:MSVC>>:SYSTEM_VOLUME_MIXER_AVAILABLE=0>
    $<$<BOOL:${NINTENDO_SWITCH}>:__SWITCH__>)

# Nintendo Switch extra setup
if (NINTENDO_SWITCH)
    # needs to be linked with C++ linker for C++ stdlib
    enable_language(CXX)
    set_target_properties(sm PROPERTIES
        CXX_STANDARD 11
        LINKER_LANGUAGE CXX)

    nx_generate_nacp(sm.nacp
        NAME "Super Metroid"
        AUTHOR "snesrev & Lywx"
        VERSION "${PROJECT_VERSION}")

    nx_create_nro(sm
        NACP sm.nacp
        ICON "${PROJECT_SOURCE_DIR}/src/platform/switch/icon.jpg")

    set(ini_name "${PROJECT_SOURCE_DIR}/src/platform/switch/sm.ini")
endif()

# Installation
# ------------
install(TARGETS sm RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(FILES "${ini_name}" DESTINATION "${CMAKE_INSTALL_BINDIR}")