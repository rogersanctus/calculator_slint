#pragma once
#include "../model/CalculatorModel.hpp"

class CalculatorViewModel {
public:
    CalculatorViewModel();

    // Exposed methods for Slint UI
    void inputDigit(int d) { m_model.inputDigit(d);  }
    void inputOperation(char op) { m_model.inputOperation(op); }
    void inputEquals() { m_model.inputEquals(); }
    void clear() { m_model.clear(); }
    void erase() { m_model.erase(); }
    std::string display() const { return m_model.display(); }

private:
    CalculatorModel m_model;
};
