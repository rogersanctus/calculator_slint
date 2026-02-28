#pragma once

class ExampleModel {
public:
    ExampleModel();
    int value() const;
    void setValue(int v);
private:
    int m_value = 0;
};
