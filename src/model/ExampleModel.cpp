#include "ExampleModel.hpp"

ExampleModel::ExampleModel() {}

int ExampleModel::value() const {
    return m_value;
}

void ExampleModel::setValue(int v) {
    m_value = v;
}
