#ifndef GEOM_H
#define GEOM_H

#include <algorithm>
#include <vector>

namespace geom {

double circumR(double radius);

double radius();

double areaCir(double radius);

double areaRect(double Length, double Width);

double areaSq(double side);

double areaTri(double base, double height);

double areaTrap(double Base1, double Base2, double Height);

double cosine(double angle);

double acos(double value);

double sine(double angle);

double tangent(double angle);

double diam(double radius);

double volumeCube(double side);

double volumeSphere(double radius);

double volumeCylinder(double radius, double height);

double volumeCone(double radius, double height);

double volumePyramid(double baseArea, double height);

double volumeRectPrism(double length, double width, double height);

double radiusD(double diameter);

double radiusC(double circumference);

double radiusA(double area);

double perimeterRect(double Length, double Width);

double perimeterSq(double side);

double perimeterTri(double side1, double side2, double side3);

double perimeterTrap(double Base1, double Base2, double side1, double side2);

double surfaceAreaCube(double side);

double surfaceAreaSphere(double radius);

double surfaceAreaCylinder(double radius, double height);

double dist_2p(double x1, double y1, double x2, double y2);

double midpoint(double x1, double y1, double x2, double y2);

double slope(double x1, double y1, double x2, double y2);

double slopeIntercept(double x1, double y1, double x2, double y2);

double crossProduct(const std::pair<double, double>& O, 
                       const std::pair<double, double>& A, 
                       const std::pair<double, double>& B);

double crossProductMagnitude(double x1, double y1, double x2, double y2);

double polygonArea(const std::vector<std::pair<double, double>>& polygon);

double convexHull_GS(const std::vector<std::pair<double, double>>& points);

double convexHull(const std::vector<std::pair<double, double>>& points);

double delaunayTriangulation(const std::vector<std::pair<double, double>>& points);

extern const double PI;

}

#endif
