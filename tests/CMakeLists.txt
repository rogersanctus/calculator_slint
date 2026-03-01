set(
  TESTS
  ./CalculatorModel_test.cpp
)

add_executable(calculator_slint_tests ${TESTS})

# Link Catch2 main and tests
target_link_libraries(
  calculator_slint_tests
  PRIVATE
  calculator_slint_lib
  Catch2::Catch2WithMain)

# Include model header path
target_include_directories(
  calculator_slint_tests
  PRIVATE
  "${CMAKE_SOURCE_DIR}/src")

# Inclui

# Enable CTest integration
include(CTest)
include(Catch)
catch_discover_tests(calculator_slint_tests)
#add_test(NAME CalculatorModelTests COMMAND calculator_slint_tests)
