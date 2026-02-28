#include "CalculatorViewModel.hpp"
#include "CalculatorView.h"
#include "slint_string.h"

CalculatorViewModel::CalculatorViewModel(CalculatorView *view) : mView(view) {
  m_model.clear();
  updateDisplay();
  setupBindings();
}

void CalculatorViewModel::updateDisplay() const {
  mView->set_display(m_model.display().c_str());
}

void CalculatorViewModel::setupBindings() {
  mView->on_inputDigit([this](int digit) {
    m_model.inputDigit(digit);
    updateDisplay();
  });

  mView->on_inputOperation([this](slint::SharedString op) {
    char opChar;

    if (!op.empty()) {
      opChar = static_cast<char>(op.begin()[0]);
      m_model.inputOperation(opChar);
      updateDisplay();
    }
  });

  mView->on_inputEquals([this] {
    m_model.inputEquals();
    updateDisplay();
  });

  mView->on_clear([this] {
    m_model.clear();
    updateDisplay();
  });

  mView->on_erase([this] {
    m_model.erase();
    updateDisplay();
  });
}
