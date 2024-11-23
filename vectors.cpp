#include "vectors.h"
#include <iostream>
#include <string_view>

/* Class constructors */
Vectors::Vectors()
{
    // Default constructor - sets coordinates to (0, 0, 0)
    i = j = k = 0;
}
Vectors::Vectors(double i, double j, double k)
{
    // Constructor with user parameters
    this->i = i;
    this->j = j;
    this->k = k;
}

/* Input - output */
void Vectors::print() const
{
    // Printing a vector as (i, j, k)
    std::cout << "(" << i << ", " << j << ", " << k << ")\n";
}
void Vectors::print(std::string_view labelResult) const
{
    // Printing a vector with a label as a prefix (for identification)
    std::cout << labelResult << ": (" << i << ", " << j << ", " << k
              << ")\n";
}
void Vectors::set(int no)
{
    // Get user input for a vector
    std::cout << "Enter (i, j, k) for vector #" << no << ": ";
    std::cin.clear();
    std::cin >> i >> j >> k;
}

/* Vector algebraic operations */
Vectors Vectors::operator+(Vectors v)
{
    // Vector addition
    Vectors result(i + v.i, j + v.j, k + v.k);
    return result;
}
Vectors Vectors::operator-(Vectors v)
{
    // Vector subtraction
    Vectors result(i - v.i, j - v.j, k - v.k);
    return result;
}
Vectors Vectors::operator*(Vectors v)
{
    // Vector cross-product
    Vectors result {};
    result.i = (j * v.k) - (v.j * k);
    result.j = (v.i * k) - (i * v.k);
    result.k = (i * v.j) - (v.i * j);
    return result;
}
Vectors Vectors::mul(double c)
{
    // Multiply a scalar with a vector
    return Vectors { c * i, c * j, c * k };
}
double Vectors::dot(Vectors v) const
{
    // Vector dot-product
    return (i * v.i) + (j * v.j) + (k * v.k);
}

bool Vectors::equals(Vectors v) const
{
    // Vector equality checker
    return i == v.i && j == v.j && k == v.k;
}

double Vectors::mag() const
{
    // Vector magnitude
    return sqrt(i * i + j * j + k * k);
}

double Vectors::angleR(Vectors v) const
{
    // Angle between vectors in radians
    return acos(dot(v) / (mag() * v.mag()));
}

double Vectors::angleD(Vectors v) const
{
    // Angle between vectors in degrees
    return angleR(v) * 57.296;
}

void Vectors::resizeTo(double m)
{
    // Resize the length of a vector
    i = i * m / mag();
    j = j * m / mag();
    k = k * m / mag();
}

Vectors Vectors::componentAlong(Vectors v)
{
    // Find the projection vector along another vector
    Vectors c = v.mul(dot(v) / (v.mag() * v.mag()));
    return c;
}

double Vectors::distanceBetween(Vectors v)
{
    // Distance between 2 vectors
    return sqrt(pow((i - v.i), 2) + pow((j - v.j), 2) + pow((k - v.k), 2));
}