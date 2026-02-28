#include "CalculatorViewModel.hpp"
#include <slint/Component.hpp>

CalculatorViewModel::CalculatorViewModel() {
    // Initialize with default display
    onDisplayChanged(m_model.display());
}
