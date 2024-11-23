#include "vectors.h"
#include "spdlog/spdlog.h"
#include <iostream>
#include <string_view>

// Class constructors
Vectors::Vectors()
{
    spdlog::get("logger")->debug("Default class constructor called.");
    i = j = k = 0;
}
Vectors::Vectors(double i, double j, double k)
{
    spdlog::get("logger")->debug("Parametrized class constructor called.");
    this->i = i;
    this->j = j;
    this->k = k;
}

// Input-output
void Vectors::print() const
{
    spdlog::get("logger")->debug("Default print() called");
    std::cout << "(" << i << ", " << j << ", " << k << ")\n";
}
void Vectors::print(std::string_view labelResult) const
{
    spdlog::get("logger")->debug("print() with label called");
    std::cout << labelResult << ": (" << i << ", " << j << ", " << k
              << ")\n";
}
void Vectors::set(int no)
{
    spdlog::get("logger")->debug("set() called");
    std::cout << "Enter (i, j, k) for vector #" << no << ": ";
    std::cin.clear();
    std::cin >> i >> j >> k;
}

// Vector algebraic operations
Vectors Vectors::operator+(Vectors v)
{
    spdlog::get("logger")->debug("Vectors added");
    Vectors result(i + v.i, j + v.j, k + v.k);
    return result;
}
Vectors Vectors::operator-(Vectors v)
{
    spdlog::get("logger")->debug("Vectors subtracted");
    Vectors result(i - v.i, j - v.j, k - v.k);
    return result;
}
Vectors Vectors::operator*(Vectors v)
{
    spdlog::get("logger")->debug("Vectors cross multipled");
    Vectors result {};
    result.i = (j * v.k) - (v.j * k);
    result.j = (v.i * k) - (i * v.k);
    result.k = (i * v.j) - (v.i * j);
    return result;
}
Vectors Vectors::mul(double c)
{
    spdlog::get("logger")->debug("Vector scalar multiplied");
    return Vectors { c * i, c * j, c * k };
}
double Vectors::dot(Vectors v) const
{
    return (i * v.i) + (j * v.j) + (k * v.k);
}

/* Tests were conducted using std::chrono::high_resolution_clock and it turns
 * out that the return expression that was commented out is actually less
 * efficient, the new expression is slightly faster to evaluate.
 * Average difference between dot and cross over 10 runs: +0.08968ms
 */
Vectors Vectors::vectorTripleProductL(Vectors v1, Vectors v2, Vectors v3)
{
    spdlog::get("logger")->debug("Vector triple product (v1 * v2) * v3");
    return Vectors { (v1 * v2) * v3 };
    // return Vectors { v2.mag(v1.dot(v3)) - v1.mag(v2.dot(v3)) };
}
Vectors Vectors::vectorTripleProductR(Vectors v1, Vectors v2, Vectors v3)
{
    spdlog::get("logger")->debug("Vector triple product v1 * (v2 * v3)");
    return Vectors { v1 * (v2 * v3) };
    // return Vectors { v2.mag(v1.dot(v3)) - v3.mag(v1.dot(v2)) };
}

bool Vectors::equals(Vectors v) const
{
    return i == v.i && j == v.j && k == v.k;
}

double Vectors::mag() const
{
    return sqrt(i * i + j * j + k * k);
}

double Vectors::angleR(Vectors v) const
{
    return acos(dot(v) / (mag() * v.mag()));
}

double Vectors::angleD(Vectors v) const
{
    return angleR(v) * 57.296;
}

void Vectors::resizeTo(double m)
{
    i = i * m / mag();
    j = j * m / mag();
    k = k * m / mag();
}

Vectors Vectors::componentAlong(Vectors v)
{
    Vectors c = v.mul(dot(v) / (v.mag() * v.mag()));
    return c;
}

double Vectors::distanceBetween(Vectors v)
{
    return sqrt(pow((i - v.i), 2) + pow((j - v.j), 2) + pow((k - v.k), 2));
}