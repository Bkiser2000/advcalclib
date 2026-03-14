#include <iostream>
#include <vector>
#include <algorithm>
#include "geom.hpp"
#include "calc.hpp"
#include "algebra.hpp"

namespace geom {

const double PI = 3.141592;

struct Triangle {
    int a, b, c; // indices of points
    
    bool circumcircleContains(const std::pair<double, double>& p, 
                             const std::vector<std::pair<double, double>>& points) const {
        auto& pa = points[a];
        auto& pb = points[b];
        auto& pc = points[c];
        
        double ax = pa.first - p.first;
        double ay = pa.second - p.second;
        double bx = pb.first - p.first;
        double by = pb.second - p.second;
        double cx = pc.first - p.first;
        double cy = pc.second - p.second;
        
        double d = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
        if (d == 0) return false;
        
        double ux = ((ax*ax + ay*ay) * (by - cy) + (bx*bx + by*by) * (cy - ay) + (cx*cx + cy*cy) * (ay - by)) / d;
        double uy = ((ax*ax + ay*ay) * (cx - bx) + (bx*bx + by*by) * (ax - cx) + (cx*cx + cy*cy) * (bx - ax)) / d;
        
        double r2 = ux*ux + uy*uy;
        double dist2 = ax*ax + ay*ay;
        
        return dist2 < r2;
    }
};

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

double acos(double value) {
    if (value < -1 || value > 1) {
        std::cerr << "Error: Input must be in the range [-1, 1]\n";
        return -1;
    }
    double angle = 0;
    double term = 1;
    int n = 0;
    while (abs(term) > 0.00001) {
        term *= (value * value * (2 * n + 1)) / (2 * n + 3);
        angle += term;
        n++;
    }
    return angle;
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

double surfaceAreaCone(double radius, double slantHeight) {
    double surfaceArea;
    if (radius > 0 && slantHeight > 0) {
        surfaceArea = PI * radius * (radius + slantHeight);
        //cout << "Surface Area: " << surfaceArea << "\n";
        return surfaceArea;
    } else {
        std::cerr << "Error: Radius and slant height must be positive!" << "\n";
        return -1;
    }
}

double surfaceAreaRectPrism(double length, double width, double height) {
    double surfaceArea;
    if (length > 0 && width > 0 && height > 0) {
        surfaceArea = 2 * (length * width + length * height + width * height);
        //cout << "Surface Area: " << surfaceArea << "\n";
        return surfaceArea;
    } else {
        std::cerr << "Error: Length, width, and height must be positive!" << "\n";
        return -1;
    }

}

double dist_2p(double x1, double y1, double x2, double y2) {
    double distance;
    distance = calc::squrt(calc::expo(x2 - x1, 2) + calc::expo(y2 - y1, 2));
    //cout << "Distance: " << distance << "\n";
    return distance;

}

double midpoint(double x1, double y1, double x2, double y2) {
    double midX = (x1 + x2) / 2;
    double midY = (y1 + y2) / 2;
    //cout << "Midpoint: (" << midX << ", " << midY << ")\n";
    return midX, midY;
}

double slope(double x1, double y1, double x2, double y2) {
    if (x2 - x1 != 0) {
        double slope = (y2 - y1) / (x2 - x1);
        //cout << "Slope: " << slope << "\n";
        return slope;
    } else {
        std::cerr << "Error: Slope is undefined for vertical lines!" << "\n";
        return -1;
    }

}

double slopeIntercept(double x1, double y1, double x2, double y2) {
    if (x2 - x1 != 0) {
        double m = (y2 - y1) / (x2 - x1);
        double b = y1 - m * x1;
        //cout << "Slope: " << m << ", Intercept: " << b << "\n";
        return b;
    } else {
        std::cerr << "Error: Slope is undefined for vertical lines!" << "\n";
        return -1;
    }
}

double crossProduct(const std::pair<double, double>& O, 
                       const std::pair<double, double>& A, 
                       const std::pair<double, double>& B) {
        return (A.first - O.first) * (B.second - O.second) - 
               (A.second - O.second) * (B.first - O.first);
}

double crossProductMagnitude(double x1, double y1, double x2, double y2) {
    double crossProdMag = abs(x1 * y2 - y1 * x2);
    //cout << "Cross Product Magnitude: " << crossProdMag << "\n";
    return crossProdMag;
}

double polygonArea(const std::vector<std::pair<double, double>>& polygon) {
    if (polygon.size() < 3) return 0;
        
    double area = 0;
    for (size_t i = 0; i < polygon.size(); i++) {
        size_t j = (i + 1) % polygon.size();
        area += polygon[i].first * polygon[j].second;
        area -= polygon[j].first * polygon[i].second;
    }
    return calc::squrt(area * area) / 2.0; // Absolute value
}

// Graham Scan algorithm for convex hull
double convexHull_GS(const std::vector<std::pair<double, double>>& points) {
    if (points.size() < 3) {
        std::cerr << "Error: Need at least 3 points for convex hull!" << "\n";
        return -1;
    }
    
    std::vector<std::pair<double, double>> pts = points;
    
    // Find the point with lowest y-coordinate (and leftmost if tie)
    size_t minIdx = 0;
    for (size_t i = 1; i < pts.size(); i++) {
        if (pts[i].second < pts[minIdx].second ||
            (pts[i].second == pts[minIdx].second && pts[i].first < pts[minIdx].first)) {
            minIdx = i;
        }
    }
    
    // Move start point to beginning
    std::swap(pts[0], pts[minIdx]);
    std::pair<double, double> start = pts[0];
    
    // Sort points by polar angle with respect to start point
    std::sort(pts.begin() + 1, pts.end(), 
        [&start](const std::pair<double, double>& a, const std::pair<double, double>& b) {
            double v = geom::crossProduct(start, a, b);
            if (v == 0) {
                // Collinear: sort by distance
                double distA = calc::squrt(calc::expo(a.first - start.first, 2) + 
                                          calc::expo(a.second - start.second, 2));
                double distB = calc::squrt(calc::expo(b.first - start.first, 2) + 
                                          calc::expo(b.second - start.second, 2));
                return distA < distB;
            }
            return v > 0;
        });
    
    // Build convex hull
    std::vector<std::pair<double, double>> hull;
    for (size_t i = 0; i < pts.size(); i++) {
        // Remove points that make clockwise turn
        while (hull.size() > 1 && 
               geom::crossProduct(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    
    // Calculate area
    return geom::polygonArea(hull);
}

// Convex Hull using Andrew's Monotone Chain Algorithm (alternative)
double convexHull(const std::vector<std::pair<double, double>>& points) {
    if (points.size() < 3) {
        std::cerr << "Error: Need at least 3 points for convex hull!" << "\n";
        return -1;
    }
    
    std::vector<std::pair<double, double>> pts = points;
    
    // Sort points lexicographically
    std::sort(pts.begin(), pts.end());
    
    // Build lower hull
    std::vector<std::pair<double, double>> lower;
    for (size_t i = 0; i < pts.size(); i++) {
        while (lower.size() >= 2 && 
               geom::crossProduct(lower[lower.size()-2], lower[lower.size()-1], pts[i]) <= 0) {
            lower.pop_back();
        }
        lower.push_back(pts[i]);
    }
    
    // Build upper hull
    std::vector<std::pair<double, double>> upper;
    for (int i = (int)pts.size() - 1; i >= 0; i--) {
        while (upper.size() >= 2 && 
               geom::crossProduct(upper[upper.size()-2], upper[upper.size()-1], pts[i]) <= 0) {
            upper.pop_back();
        }
        upper.push_back(pts[i]);
    }
    
    // Remove last point of each half because it's repeated
    lower.pop_back();
    upper.pop_back();
    
    // Concatenate
    lower.insert(lower.end(), upper.begin(), upper.end());
    
    // Calculate area
    return geom::polygonArea(lower);
}

double delaunayTriangulation(const std::vector<std::pair<double, double>>& points) {
    if (points.size() < 3) {
        std::cerr << "Error: Need at least 3 points for triangulation!" << "\n";
        return -1;
    }
    
    std::vector<std::pair<double, double>> pts = points;
    
    // Find bounding box
    double minX = pts[0].first, maxX = pts[0].first;
    double minY = pts[0].second, maxY = pts[0].second;
    
    for (const auto& p : pts) {
        minX = (p.first < minX) ? p.first : minX;
        maxX = (p.first > maxX) ? p.first : maxX;
        minY = (p.second < minY) ? p.second : minY;
        maxY = (p.second > maxY) ? p.second : maxY;
    }
    
    double dx = maxX - minX;
    double dy = maxY - minY;
    double delta = (dx > dy) ? dx : dy;
    double mid = (minX + maxX) / 2;
    
    // Add super-triangle
    pts.push_back({mid - 20*delta, minY - delta});
    pts.push_back({mid, maxY + 20*delta});
    pts.push_back({mid + 20*delta, minY - delta});
    
    std::vector<Triangle> triangles;
    triangles.push_back({(int)pts.size()-3, (int)pts.size()-2, (int)pts.size()-1});
    
    // Incremental Delaunay insertion
    for (int i = 0; i < (int)points.size(); i++) {
        std::vector<Triangle> badTriangles;
        
        // Find triangles whose circumcircle contains the point
        for (const auto& t : triangles) {
            if (t.circumcircleContains(pts[i], pts)) {
                badTriangles.push_back(t);
            }
        }
        
        // Find boundary edges of bad triangles
        std::vector<std::pair<int, int>> polygon;
        for (const auto& t : badTriangles) {
            std::vector<std::pair<int, int>> edges = {{t.a, t.b}, {t.b, t.c}, {t.c, t.a}};
            
            for (const auto& e : edges) {
                bool shared = false;
                for (const auto& t2 : badTriangles) {
                    if (&t2 == &t) continue;
                    if ((e.first == t2.a || e.first == t2.b || e.first == t2.c) &&
                        (e.second == t2.a || e.second == t2.b || e.second == t2.c)) {
                        shared = true;
                        break;
                    }
                }
                if (!shared) {
                    polygon.push_back(e);
                }
            }
        }
        
        // Remove bad triangles
        triangles.erase(
            std::remove_if(triangles.begin(), triangles.end(),
                [&badTriangles](const Triangle& t) {
                    return std::find_if(badTriangles.begin(), badTriangles.end(),
                        [&t](const Triangle& bt) {
                            return t.a == bt.a && t.b == bt.b && t.c == bt.c;
                        }) != badTriangles.end();
                }),
            triangles.end()
        );
        
        // Create new triangles
        for (const auto& e : polygon) {
            triangles.push_back({e.first, e.second, i});
        }
    }
    
    // Remove triangles with super-triangle vertices
    int superTriStart = points.size();
    triangles.erase(
        std::remove_if(triangles.begin(), triangles.end(),
            [superTriStart](const Triangle& t) {
                return t.a >= superTriStart || t.b >= superTriStart || t.c >= superTriStart;
            }),
        triangles.end()
    );
    
    // Calculate total area
    double totalArea = 0;
    for (const auto& t : triangles) {
        auto& pa = points[t.a];
        auto& pb = points[t.b];
        auto& pc = points[t.c];
        
        double area = calc::squrt(
            calc::expo((pb.first - pa.first) * (pc.second - pa.second) - 
                      (pc.first - pa.first) * (pb.second - pa.second), 2)
        ) / 2.0;
        totalArea += area;
    }
    
    return totalArea;
}

double fourierTransform(const std::vector<double>& signal) {
    // This is a placeholder for the actual implementation of the Fourier Transform.
    // The actual implementation would involve computing the discrete Fourier transform of the input signal.
    std::cerr << "Error: Fourier Transform algorithm not implemented yet!" << "\n";
    return -1;
}
}