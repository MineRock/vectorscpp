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
    void print(Vectors v) const;
    static void print(Vectors v, std::string_view labelResult);
    static Vectors set(int no);
    Vectors operator+(Vectors v);
    Vectors operator-(Vectors v);
    Vectors operator*(Vectors v);
    Vectors mul(double c);
    double dot(Vectors v) const;
    bool operator==(Vectors v) const;
    double mag() const;
    double angleR(Vectors v) const;
    double angleD(Vectors v) const;
    Vectors resizeTo(double m);
    Vectors componentAlong(Vectors v);
    double distanceBetween(Vectors v);
};
