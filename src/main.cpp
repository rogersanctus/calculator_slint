#include <slint/Component.hpp>
#include <slint/Window.hpp>
#include "../model/CalculatorModel.hpp"
#include "../viewmodel/CalculatorViewModel.hpp"

int main(int argc, char* argv[]) {
    // Build the Slint component
    auto component = slint::Component::create("CalculatorView.slint");
    auto viewModel = std::make_shared<CalculatorViewModel>();
    component->set_data(viewModel);

    auto window = component->create_window();
    window->show();
    return component->run();
}
