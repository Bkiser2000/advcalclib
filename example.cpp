#include <iostream>
#include <calc.hpp>
#include <elec.hpp>
#include <geom.hpp>
#include <physics.hpp>
#include <algebra.hpp>
//#include "algebra.hpp"
//#include "calc.hpp"
//#include "physics.hpp"
//#include "geom.hpp"
//#include "elec.hpp"
#include <string>
#include <iomanip>

int main() {
  double result;
  calc::squrt(16);
  std::cout << calc::add(5, 5) << "\n";
  result = calc::add(6, 8);
  if (result > 5) {
    std::cout << "The sum is greater than 5\n";
  } else {
    std::cout << "The sum is not greater than 5\n";
  }
  algebra::solveLinear(2, 3, 11);
  algebra::solveQuadratic(1, -5, 6);
  std::cout << calc::sub(10, 3) << "\n";
  std::cout << calc::mult(4, 5) << "\n";
  std::cout << calc::div(20, 4) << "\n";
  std::cout << calc::expo(2, 3) << "\n"; 
  double values[] = {3.3, 2.2, 1.1, 4.7};
  calc::mean(values, 4);
  double values1[] = {5, 2, 4.20, 6, 9};
  calc::median(values1, 5);
  double modeArr[] = {2, 2, 5, 7, 3, 3, 2};
  result = calc::mode(modeArr, 7);
  std::cout << "Mode: " << result << "\n";
  double seriesResistors[] = {10, 20, 30};
  std::cout << elec::calculateSeries_Resis(seriesResistors, 3) << "\n";
  double paralResistors[] = {10, 20, 30};
  std::cout << elec::calculateParal_Resis(paralResistors, 3) << "\n";
  std::cout << calc::degrees_F(40);
  calc::degrees_C(80);
  geom::areaRect(5, 10);
  physics::density(10, 5);
  geom::circumR(7);
  geom::cosine(60);
  geom::sine(30);
  geom::tangent(45);
  geom::radiusD(10);
  geom::diam(5);
  return 0;
}



