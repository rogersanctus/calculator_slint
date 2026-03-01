#include "model/CalculatorModel.hpp"
#include <catch2/catch_test_macros.hpp>

#include "model/CalculatorModel.hpp"

TEST_CASE("CalculatorModel default state", "[CalculatorModel]") {
  CalculatorModel model;
  REQUIRE(model.display() == "0");
}

TEST_CASE("CalculatorModel basic operations", "[CalculatorModel]") {
  CalculatorModel model;
  // 2 + 3 = 5
  model.inputDigit(2);
  model.inputOperation('+');
  model.inputDigit(3);
  model.inputEquals();
  REQUIRE(model.display() == "5");

  // 5 * 4 = 20
  model.inputOperation('*');
  model.inputDigit(4);
  model.inputEquals();
  REQUIRE(model.display() == "20");

  // 20 - 5 = 15
  model.inputOperation('-');
  model.inputDigit(5);
  model.inputEquals();
  REQUIRE(model.display() == "15");

  // 15 / 3 = 5
  model.inputOperation('/');
  model.inputDigit(3);
  model.inputEquals();
  REQUIRE(model.display() == "5");

  // 5 % 2 = 1
  model.inputOperation('%');
  model.inputDigit(2);
  model.inputEquals();
  REQUIRE(model.display() == "1");
}

TEST_CASE("CalculatorModel clear and erase", "[CalculatorModel]") {
  CalculatorModel model;
  model.inputDigit(9);
  model.inputDigit(8);
  REQUIRE(model.display() == "98");
  model.erase();
  REQUIRE(model.display() == "9");
  model.erase();
  REQUIRE(model.display() == "0");
  model.erase();
  REQUIRE(model.display() == "0");
  model.inputDigit(4);
  model.inputOperation('*');
  model.inputDigit(5);
  model.inputEquals();
  REQUIRE(model.display() == "20");
  model.clear();
  REQUIRE(model.display() == "0");
}

TEST_CASE("Division and modulus by zero handled", "[CalculatorModel]") {
  CalculatorModel model;
  model.inputDigit(1);
  model.inputOperation('/');
  model.inputDigit(0);
  model.inputEquals();
  REQUIRE(model.display() == "0");

  model.clear();
  model.inputDigit(5);
  model.inputOperation('%');
  model.inputDigit(0);
  model.inputEquals();
  REQUIRE(model.display() == "5"); // fallback to rhs
}
