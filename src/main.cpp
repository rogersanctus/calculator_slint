#include "CalculatorView.h"
#include "./model/CalculatorModel.hpp"
#include "./viewmodel/CalculatorViewModel.hpp"

int main(int argc, char* argv[]) {
    // Build the Slint component
    auto ui = CalculatorView::create();
    auto viewModel = std::make_shared<CalculatorViewModel>();
    ui->on_clear([]() -> viewModel.clear);
//    component->set_data(viewModel);
//
//    auto window = component->create_window();
    // window->show();
    ui->run();
    return 0;
}
