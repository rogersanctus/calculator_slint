#include "CalculatorModel.hpp"
#include <cmath>

CalculatorModel::CalculatorModel()
    : m_display("0"), m_accumulator(0), m_pendingOp(0), m_newInput(true) {}

std::string CalculatorModel::display() const { return m_display; }

void CalculatorModel::inputDigit(int d) {
  if (m_newInput) {
    m_display = std::to_string(d);
    m_newInput = false;
  } else {
    if (m_display == "0")
      m_display = std::to_string(d);
    else
      m_display += std::to_string(d);
  }
}

void CalculatorModel::inputOperation(char op) {
  double value = std::stod(m_display);
  if (m_pendingOp) {
    m_accumulator = compute(m_accumulator, value, m_pendingOp);
  } else {
    m_accumulator = value;
  }
  m_pendingOp = op;
  m_newInput = true;
}

void CalculatorModel::inputEquals() {
  double value = std::stod(m_display);
  if (m_pendingOp) {
    m_accumulator = compute(m_accumulator, value, m_pendingOp);
    m_pendingOp = 0;
  }
  m_display = std::to_string(m_accumulator);
  // Remove trailing zeros
  m_display.erase(m_display.find_last_not_of('0') + 1, std::string::npos);
  if (!m_display.empty() && m_display.back() == '.')
    m_display.pop_back();
  m_newInput = true;
}

void CalculatorModel::clear() {
  m_display = "0";
  m_accumulator = 0;
  m_pendingOp = 0;
  m_newInput = true;
}

void CalculatorModel::erase() {
  if (m_display.size() > 1) {
    m_display.pop_back();
  } else {
    m_display = "0";
  }
  m_newInput = false;
}

double CalculatorModel::compute(double lhs, double rhs, char op) const {
  switch (op) {
  case '+':
    return lhs + rhs;
  case '-':
    return lhs - rhs;
  case '*':
    return lhs * rhs;
  case '/':
    return rhs != 0.0 ? lhs / rhs : 0.0;
  case '%':
    return std::fmod(lhs, rhs);
  default:
    return rhs;
  }
}
