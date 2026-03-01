# Build the application library
set(
  SOURCES
  ./main.cpp
)

# Define the executable
add_executable(calculator_slint_app ${SOURCES})

add_library(calculator_slint_lib
  STATIC
  ./model/CalculatorModel.cpp
  ./viewmodel/CalculatorViewModel.cpp)

# Inclui a lib no target calculator_slint_lib
target_include_directories(
  calculator_slint_lib
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
  calculator_slint_lib
  PUBLIC Slint::Slint)

# Link libraries
target_link_libraries(
  calculator_slint_app
  PRIVATE
  calculator_slint_lib)

# Include directories - add build directory for generated headers
target_include_directories(calculator_slint_lib PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Slint source files
set(SLINT_SOURCES
    ./view/CalculatorView.slint
)

# Generate C++ sources from Slint UI
slint_target_sources(calculator_slint_lib ${SLINT_SOURCES})
