#pragma once
#include "../model/CalculatorModel.hpp"
#include "CalculatorView.h"
#include <slint.h>
#include <vector>

class CalculatorViewModel {
public:
  CalculatorViewModel(CalculatorView *view);

private:
  CalculatorModel m_model;
  CalculatorView *mView;

  std::vector<ScoppedConnection> connections;

  void setupBindings();
};
