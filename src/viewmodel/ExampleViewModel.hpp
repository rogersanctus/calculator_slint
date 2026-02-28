#pragma once
#include "../model/ExampleModel.hpp"

class ExampleViewModel {
public:
    ExampleViewModel(ExampleModel* model);
    int value() const;
    void setValue(int v);
private:
    ExampleModel* m_model;
};
