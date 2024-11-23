#pragma once
#include <iostream>
#include <string_view>

class Vectors {
private:
    double i {};
    double j {};
    double k {};

public:
    Vectors();
    Vectors(double i, double j, double k);
    void print() const;
    void print(std::string_view labelResult) const;
    void set(int no);
    Vectors operator+(Vectors v);
    Vectors operator-(Vectors v);
    Vectors operator*(Vectors v);
    Vectors mul(double c);
    double dot(Vectors v) const;
    static Vectors vectorTripleProductL(Vectors v1, Vectors v2, Vectors v3);
    static Vectors vectorTripleProductR(Vectors v1, Vectors v2, Vectors v3);
    bool equals(Vectors v) const;
    double mag() const;
    double angleR(Vectors v) const;
    double angleD(Vectors v) const;
    void resizeTo(double m);
    Vectors componentAlong(Vectors v);
    double distanceBetween(Vectors v);
};
