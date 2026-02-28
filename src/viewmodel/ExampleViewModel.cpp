#include "ExampleViewModel.hpp"

ExampleViewModel::ExampleViewModel(ExampleModel* model)
    : m_model(model) {}

int ExampleViewModel::value() const {
    return m_model ? m_model->value() : 0;
}

void ExampleViewModel::setValue(int v) {
    if (m_model) m_model->setValue(v);
}
