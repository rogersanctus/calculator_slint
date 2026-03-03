#include "CalculatorView.h"
#include "viewmodel/CalculatorViewModel.hpp"

int main(int argc, char *argv[]) {
  // Create the View
  auto ui = CalculatorView::create();

  {
    CalculatorViewModel viewModel(&*ui);

    // Show and run the window
    ui->show();
    ui->run();
  }

  return 0;
}
