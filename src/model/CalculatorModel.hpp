#pragma once
#include <string>

class CalculatorModel {
public:
  CalculatorModel();
  [[nodiscard]] std::string display() const;

  void inputDigit(int d);
  void inputOperation(char op);
  void inputEquals();
  void clear();
  void erase();

private:
  std::string m_display = "0";
  double m_accumulator;
  char m_pendingOp;
  bool m_newInput;
  double compute(double lhs, double rhs, char op) const;
};
