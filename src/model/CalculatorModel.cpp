#include "CalculatorModel.hpp"
#include <cmath>

CalculatorModel::CalculatorModel()
    : mDisplay("0"), mAccumulator(0), mPendingOp(0), mNewInput(true) {}

std::string CalculatorModel::display() const { return mDisplay; }

void CalculatorModel::inputDigit(int d) {
  if (mNewInput) {
    mDisplay = std::to_string(d);
    mNewInput = false;
  } else {
    if (mDisplay == "0")
      mDisplay = std::to_string(d);
    else
      mDisplay += std::to_string(d);
  }

  onDisplayChanged.emit(mDisplay);
}

void CalculatorModel::inputOperation(char op) {
  double value = std::stod(mDisplay);
  if (mPendingOp) {
    mAccumulator = compute(mAccumulator, value, mPendingOp);
  } else {
    mAccumulator = value;
  }
  mPendingOp = op;
  mNewInput = true;
}

void CalculatorModel::inputEquals() {
  double value = std::stod(mDisplay);
  if (mPendingOp) {
    mAccumulator = compute(mAccumulator, value, mPendingOp);
    mPendingOp = 0;
  }
  mDisplay = std::to_string(mAccumulator);
  // Remove trailing zeros
  mDisplay.erase(mDisplay.find_last_not_of('0') + 1, std::string::npos);
  if (!mDisplay.empty() && mDisplay.back() == '.')
    mDisplay.pop_back();
  mNewInput = true;

  onDisplayChanged.emit(mDisplay);
}

void CalculatorModel::clear() {
  mDisplay = "0";
  mAccumulator = 0;
  mPendingOp = 0;
  mNewInput = true;

  onDisplayChanged.emit(mDisplay);
}

void CalculatorModel::erase() {
  if (mDisplay.size() > 1) {
    mDisplay.pop_back();
  } else {
    mDisplay = "0";
  }
  mNewInput = false;

  onDisplayChanged.emit(mDisplay);
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
