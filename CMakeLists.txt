# Enable VCPKG toolchain
set(
  CMAKE_TOOLCHAIN_FILE
  "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
  CACHE FILEPATH "Path to toolchain")

cmake_minimum_required(VERSION 3.24)

project(qween_coder_test LANGUAGES CXX)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(CONFIGURATION_LOG " TOOLCHAIN ${CMAKE_TOOLCHAIN_FILE}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find packages
find_package(slint QUIET)

if (NOT Slint_FOUND)
  message(
    "Slint could not be located in the CMake module search path. Downloading it from Git and building it locally"
  )

  include(FetchContent)

  FetchContent_Declare(
    Slint
    GIT_REPOSITORY https://github.com/slint-ui/slint.git
    # `release/1` will auto-upgrade to the latest Slint >= 1.0.0 and < 2.0.0
    # `release/1.0` will auto-upgrade to the latest Slint >= 1.0.0 and < 1.1.0
    GIT_TAG release/1
    SOURCE_SUBDIR api/cpp
  )
  FetchContent_MakeAvailable(Slint)
endif (NOT Slint_FOUND)

# Add Catch2 testing framework
find_package(Catch2 CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)
