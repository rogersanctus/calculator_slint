#pragma once
#include "signals/Signal.hpp"
#include <string>

class CalculatorModel {
public:
  CalculatorModel();
  [[nodiscard]] std::string display() const;
  Signal<std::string> onDisplayChanged;

  void inputDigit(int d);
  void inputOperation(char op);
  void inputEquals();
  void clear();
  void erase();

private:
  std::string mDisplay = "0";
  double mAccumulator;
  char mPendingOp;
  bool mNewInput;
  double compute(double lhs, double rhs, char op) const;
};
