#include "CalculatorViewModel.hpp"
#include "CalculatorView.h"
#include "slint_string.h"
#include <string>

CalculatorViewModel::CalculatorViewModel(CalculatorView *view) : mView(view) {
  m_model.clear();
  setupBindings();
}

void CalculatorViewModel::setupBindings() {
  connections.push_back(m_model.on_display_changed.connect(
      [this](const std::string &val) { mView->set_display(val.c_str()); }));

  mView->on_inputDigit([this](int digit) { m_model.inputDigit(digit); });

  mView->on_inputOperation([this](slint::SharedString op) {
    char opChar;

    if (!op.empty()) {
      opChar = static_cast<char>(op.begin()[0]);
      m_model.inputOperation(opChar);
    }
  });

  mView->on_inputEquals([this] { m_model.inputEquals(); });

  mView->on_clear([this] { m_model.clear(); });

  mView->on_erase([this] { m_model.erase(); });
}
