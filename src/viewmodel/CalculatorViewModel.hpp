#pragma once
#include "../model/CalculatorModel.hpp"
#include "CalculatorView.h"
#include <slint.h>

class CalculatorViewModel {
public:
  CalculatorViewModel(CalculatorView *view);

private:
  CalculatorModel m_model;
  CalculatorView *mView;

  // Helper to notify UI that display changed
  void updateDisplay() const;

  void setupBindings();
};
