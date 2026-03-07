#include <iostream>
#include "geom.hpp"
#include "calc.hpp"

namespace geom {

const double PI = 3.141592;

double cosine(double angle) {
    double radians = angle * (PI / 180);
    double cosValue = 1;
    double term = 1;
    int n = 0;
    while (abs(term) > 0.00001) {
        term *= -radians * radians / ((n + 1) * (n + 2));
        cosValue += term;
        n += 2;
    }
    //cout << "Cosine: " << cosValue << "\n";
    return cosValue;
}

double sine(double angle) {
    double radians = angle * (PI / 180);
    double sinValue = radians;
    double term = radians;
    int n = 1;
    while (abs(term) > 0.00001) {
        term *= -radians * radians / ((n + 1) * (n + 2));
        sinValue += term;
        n += 2;
    }
    //cout << "Sine: " << sinValue << "\n";
    return sinValue;
}

double tangent(double angle) {
    double tanValue = sine(angle) / cosine(angle);
    //cout << "Tangent: " << tanValue << "\n";
    return tanValue;
}

double radiusD(double diameter) {
    if (diameter > 0) {
        double radius = diameter / 2;
        //cout << "The radius of the circle is: " << radius << std::endl;
        return radius;
    } else {
        std::cerr << "Error: Diameter must be positive!" << "\n";
        return -1;
    }
}

double diam(double radius) {
    if (radius > 0) {
        double diameter = radius * 2;
        //cout << "The diameter of the circle is: " << diameter << "\n";
        return diameter;
    } else {
        std::cerr << "Error: Radius must be positive!" << "\n";
        return -1;
    }
}

double circumR(double radius) {
    double circumference;
    if (radius > 0) {
        circumference = 2 * PI * radius;
        //cout << "Circumference: " << circumference << "\n";
        return circumference;
    } else {
        std::cerr << "Radius cannot be zero or negative!" << "\n";
        return -1;
    }
}


double volumeCube(double side) {
    double volume;
    if (side > 0) {
        volume = calc::expo(side, 3);
        //cout << "Volume: " << volume << "\n";
        return volume;
    } else {
        std::cerr << "Error: Side length must be positive!" << "\n";
        return -1;
    }
}

double volumeSphere(double radius) {
    double volume;
    if (radius > 0) {
        volume = (4.0 / 5.0) * PI * calc::expo(radius, 3);
        //cout << "Volume: " << volume << "\n";
        return volume;
    } else {
        std::cerr << "Error: Radius must be positive!" << "\n";
        return -1;
    }
}

double volumeCylinder(double radius, double height) {
    double volume;
    if (radius > 0 && height > 0) {
        volume = PI * calc::expo(radius, 2) * height;
        //cout << "Volume: " << volume << "\n";
        return volume;
    } else {
        std::cerr << "Error: Radius and height must be positive!" << "\n";
        return -1;
    }
}

double volumeCone(double radius, double height) {
    double volume;
    if (radius > 0 && height > 0) {
        volume = (1.0 / 3.0) * geom::PI * calc::expo(radius, 2) * height;
        //cout << "Volume: " << volume << "\n";
        return volume;
    } else {
        std::cerr << "Error: Radius and height must be positive!" << "\n";
        return -1;
    }
}

double volumeRectPrism(double length, double width, double height) {
    double volume;
    if (length > 0 && width > 0 && height > 0) {
        volume = length * width * height;
        //cout << "Volume: " << volume << "\n";
        return volume;
    } else {
        std::cerr << "Error: Length, width, and height must be positive!" << "\n";
        return -1;
    }
}

double volumePyramid(double baseArea, double height) {
    double volume;
    if (baseArea > 0 && height > 0) {
        volume = (1.0 / 3.0) * baseArea * height;
        //cout << "Volume: " << volume << "\n";
        return volume;
    } else {
        std::cerr << "Error: Base area and height must be positive!" << "\n";
        return -1;
    }
}

double areaCir(double radius) {
    double area_Cir;
    double r2 = calc::expo(radius, 2);
    if (radius > 0) {
        area_Cir = PI * r2;
        //cout << "The area of the circle is: " << area_Cir << "\n";
        return area_Cir;
    } else {
        std::cerr << "Error: Radius cannot be zero or negative!" << "\n";
        return -1;
    }
    return area_Cir;
}

double radiusC(double circumference) {
    double radius;
    if (circumference > 0) {
        radius = circumference / (2 * PI);
        //cout << "The radius of the circle is: " << radius << "\n";
        return radius;
    } else {
        std::cerr << "Error: Circumference must be positive!" << "\n";
        return -1;
    }
}

double radiusA(double area) {
    double radius;
    if (area > 0) {
        radius = calc::squrt(area / PI);
        //cout << "The radius of the circle is: " << radius << "\n";
        return radius;
    } else {
        std::cerr << "Error: Area must be positive!" << "\n";
        return -1;
    }
}

double areaSq(double side) {
    double areaSq;
    if (side > 0) {
        areaSq = side * side;
        //cout << "Area: " << areaSq << "\n";
        return areaSq;
    } else {
        std::cerr << "Error: Side length cannot be zero or negative!" << "\n";
        return -1;
    }
}

double areaRect(double Length, double Width) {
    double areaRect;
    if (Length > 0 && Width > 0) {
        areaRect = Length * Width;
        //cout << "Result: " << areaRect << "\n";
        return areaRect;
    } else {
        std::cerr << "Length or width cannot be zero or negative" << "\n";
        return -1;
    }
}

double areaTri(double Base, double Height) {
    double areaTri;
    if (Base > 0 && Height > 0) {
        areaTri = 0.5 * Base * Height;
        //cout << "Result: " << areaTri << "\n";
        return areaTri;
    } else {
        std::cerr << "Base or height cannot be zero or negative" << "\n";
        return -1;
    }
}

double areaTrap(double Base1, double Base2, double Height) {
    double areaTrap;
    if (Base1 > 0 && Base2 > 0 && Height > 0) {
        areaTrap = 0.5 * (Base1 + Base2) * Height;
        //cout << "Result: " << areaTrap << "\n";
        return areaTrap;
    } else {
        std::cerr << "Base lengths and height cannot be zero or negative" << "\n";
        return -1;
    }
}

double perimeterRect(double Length, double Width) {
    double perimeter;
    if (Length > 0 && Width > 0) {
        perimeter = 2 * (Length + Width);
        //cout << "Perimeter: " << perimeter << "\n";
        return perimeter;
    } else {
        std::cerr << "Length and width cannot be zero or negative!" << "\n";
        return -1;
    }
}

double perimeterSq(double side) {
    double perimeter;
    if (side > 0) {
        perimeter = 4 * side;
        //cout << "Perimeter: " << perimeter << "\n";
        return perimeter;
    } else {
        std::cerr << "Error: Side length cannot be zero or negative!" << "\n";
        return -1;
    }
}

double perimeterTri(double side1, double side2, double side3) {
    double perimeter;
    if (side1 > 0 && side2 > 0 && side3 > 0) {
        perimeter = side1 + side2 + side3;
        //cout << "Perimeter: " << perimeter << "\n";
        return perimeter;
    } else {
        std::cerr << "Error: Side lengths must be positive!" << "\n";
        return -1;
    }
}

double perimeterTrap(double Base1, double Base2, double side1, double side2) {
    double perimeter;
    if (Base1 > 0 && Base2 > 0 && side1 > 0 && side2 > 0) {
        perimeter = Base1 + Base2 + side1 + side2;
        //cout << "Perimeter: " << perimeter << "\n";
        return perimeter;
    } else {
        std::cerr << "Error: Side lengths must be positive!" << "\n";
        return -1;
    }
}

double surfaceAreaCube(double side) {
    double surfaceArea;
    if (side > 0) {
        surfaceArea = 6 * calc::expo(side, 2);
        //cout << "Surface Area: " << surfaceArea << "\n";
        return surfaceArea;
    } else {
        std::cerr << "Error: Side length must be positive!" << "\n";
        return -1;
    }
}

double surfaceAreaSphere(double radius) {
    double surfaceArea;
    if (radius > 0) {
        surfaceArea = 4 * PI * calc::expo(radius, 2);
        //cout << "Surface Area: " << surfaceArea << "\n";
        return surfaceArea;
    } else {
        std::cerr << "Error: Radius must be positive!" << "\n";
        return -1;
    }
}

double surfaceAreaCylinder(double radius, double height) {
    double surfaceArea;
    if (radius > 0 && height > 0) {
        surfaceArea = 2 * PI * radius * (radius + height);
        //cout << "Surface Area: " << surfaceArea << "\n";
        return surfaceArea;
    } else {
        std::cerr << "Error: Radius and height must be positive!" << "\n";
        return -1;
    }
}
}