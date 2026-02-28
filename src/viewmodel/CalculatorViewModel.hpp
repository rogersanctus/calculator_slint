#pragma once
#include <slint/Component.hpp>
#include "../model/CalculatorModel.hpp"

class CalculatorViewModel : public slint::SignalEmitter {
public:
    CalculatorViewModel();

    // Exposed methods for Slint UI
    void inputDigit(int d) { m_model.inputDigit(d); onDisplayChanged(m_model.display()); }
    void inputOperation(char op) { m_model.inputOperation(op); onDisplayChanged(m_model.display()); }
    void inputEquals() { m_model.inputEquals(); onDisplayChanged(m_model.display()); }
    void clear() { m_model.clear(); onDisplayChanged(m_model.display()); }
    void erase() { m_model.erase(); onDisplayChanged(m_model.display()); }
    std::string display() const { return m_model.display(); }

    slint::Signal<const std::string &> onDisplayChanged;
private:
    CalculatorModel m_model;
};
