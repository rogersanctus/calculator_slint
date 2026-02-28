# Build the application library
set(
  SOURCES
  ./main.cpp
  ./model/CalculatorModel.cpp
  ./viewmodel/CalculatorViewModel.cpp
)

# Link Slint library (already fetched by root CMakeLists)
# The target slint::slint is available after FetchContent_MakeAvailable
# and will be linked below.

# Define the executable
add_executable(qween_coder_test_app ${SOURCES})
# Link executable to the library and Slint
# slint::slint is available from the fetch in the parent CMakeLists
# It will be linked automatically via target_link_libraries

# Link Slint library to library and executable
# We must explicitly link slint::slint to the library
# and then to the executable.
# (Using PRIVATE to avoid propagating to dependents.)

# Ensure slint::slint is found
# find_package(slint REQUIRED)

# Link libraries
target_link_libraries(qween_coder_test_app PRIVATE Slint::Slint)

# Slint source files
set(SLINT_SOURCES
    ./view/CalculatorView.slint
)

# Generate C++ sources from Slint UI
slint_target_sources(qween_coder_test_app ${SLINT_SOURCES})
