#include "CalculatorViewModel.hpp"
#include "CalculatorView.h"
#include "slint_string.h"
#include <string>

CalculatorViewModel::CalculatorViewModel(CalculatorView *view) : mView(view) {
  mModel.clear();
  setupBindings();
}

void CalculatorViewModel::setupBindings() {
  connections.push_back(mModel.onDisplayChanged.connect(
      [this](const std::string &val) { mView->set_display(val.c_str()); }));

  mView->on_inputDigit([this](int digit) { mModel.inputDigit(digit); });

  mView->on_inputOperation([this](slint::SharedString op) {
    char opChar;

    if (!op.empty()) {
      opChar = static_cast<char>(op.begin()[0]);
      mModel.inputOperation(opChar);
    }
  });

  mView->onInputEquals([this] { mModel.inputEquals(); });

  mView->onClear([this] { mModel.clear(); });

  mView->onErase([this] { mModel.erase(); });
}
