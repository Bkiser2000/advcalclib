#include <iostream>
#include <calc.hpp>
#include <elec.hpp>
#include <geom.hpp>
#include <stat.hpp>
#include <physics.hpp>
#include <algebra.hpp>
#include <calculus.hpp>
#include <utils.hpp>
//#include "algebra.hpp"
//#include "calc.hpp"
//#include "physics.hpp"
//#include "geom.hpp"
//#include "elec.hpp"
#include <string>
#include <iomanip>

int main() {
  double result;
  std::cout << calc::squrt(1.776125) << "\n";
  std::cout << calc::add(5, 5) << "\n";
  result = calc::add(6, 8);
  if (result > 5) {
    std::cout << "The sum is greater than 5\n";
  } else {
    std::cout << "The sum is not greater than 5\n";
  }
  std::cout << calc::fact(5) << "\n";
  algebra::solveLinear(2, 3, 11);
  algebra::solveQuadratic(1, -5, 6);
  algebra::binomialExpansion(2, 3, 3);
  algebra::printBinomialExpansion(2, 3, 3);
  std::cout << calc::sub(10, 3) << "\n";
  std::cout << calc::mult(4, 5) << "\n";
  std::cout << calc::div(20, 4) << "\n";
  std::cout << calc::expo(2, 3) << "\n"; 
  utils::saveResult("result.txt", "Square Root", calc::squrt(1.776125));
  double values[] = {3.3, 2.2, 1.1, 4.7};
  std::cout << "Mean: " << stat::mean(values, 4) << "\n";
  double values1[] = {5, 2, 4.20, 6, 9};
  std::cout << "Median: " << stat::median(values1, 5) << "\n";
  double modeArr[] = {2, 2, 5, 7, 3, 3, 2};
  result = stat::mode(modeArr, 7);
  std::cout << "Mode: " << result << "\n";
  double devValues[] = {3.3, 2.2, 1.1, 4.7};
  stat::stdDevS(devValues, 4);
  utils::outputPrecision("result.txt", 4, result);
  double seriesResistors[] = {10, 20, 30};
  std::cout << elec::calculateSeries_Resis(seriesResistors, 3) << "\n";
  double paralResistors[] = {10, 20, 30};
  std::cout << elec::calculateParal_Resis(paralResistors, 3) << "\n";
  std::cout << calc::degrees_F(40) << "\n";
  std::cout << calc::degrees_C(80) << "\n";
  std::cout << geom::areaRect(5, 10) << "\n";
  std::cout << physics::density(10, 5) << "\n";
  std::cout << geom::circumR(7) << "\n";
  std::cout << geom::cosine(60) << "\n";
  std::cout << geom::sine(30) << "\n";
  std::cout << geom::tangent(45) << "\n";
  std::cout << geom::radiusD(10) << "\n";
  std::cout << geom::diam(5) << "\n";
  auto func = [](double x) { return x * x; };  // example function
  double deriv = calculus::derivative(func, 2.0, 0.001);
  std::cout << "Derivative at x=2: " << deriv << "\n";
  return 0;
}



