#include <iostream>

#include "vectors.h"

void holdResult()  // Wait for user input before showing menu again
{
  std::cout << "Press Enter to continue!";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
  std::cout << "\033[2J\033[1;1H";  // Clear console
}

int main() {
  enum FunctionCodes {
    EXIT = 0,
    ADD = 1,
    SUBTRACT = 2,
    DOT_PRODUCT = 3,
    CROSS_PRODUCT = 4,
    SCALE_UP = 5,
    EQUALITY_CHECK = 6,
    MAGNITUDE = 7,
    ANGLE_RADIANS = 8,
    ANGLE_DEGREES = 9,
    CLAMP = 10,
    PROJECTION = 11,
    DISTANCE = 12
  };

  bool appRunning = true;
  std::cout << "Welcome to VectorsCPP Demo.\n\n";
  while (appRunning) {  // Keep running till user enters option 0
    std::cout << "Add 2 vectors (01)"
              << "\nSubtract 2 vectors (02)"
              << "\nDot product (03)"
              << "\nCross product (04)"
              << "\nScale up vector (05)"
              << "\nVector equality check (06)"
              << "\nMagnitude of a vector (07)"
              << "\nAngle [radians] between vectors (08)"
              << "\nAngle [degrees] between vectors (09)"
              << "\nClamp vector to magnitude (10)"
              << "\nProjection of vector along vector (11)"
              << "\nDistance between 2 vectors (12)"
              << "\n\nExit (0)";
    std::cout << "\nEnter your desired function: ";
    int func{};
    std::cin >> func;
    switch (func) {
      case EXIT:
        std::cout << "Goodbye!\n";
        appRunning = false;
        break;
      case ADD: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        Vectors::print(v1 + v2, "Sum");
        holdResult();
        break;
      }
      case SUBTRACT: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        Vectors::print(v1 - v2, "Difference");
        holdResult();
        break;
      }
      case DOT_PRODUCT: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        std::cout << "Dot product: " << v1.dot(v2) << "\n";
        holdResult();
        break;
      }
      case CROSS_PRODUCT: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        Vectors::print(v1 * v2, "Cross product");
        holdResult();
        break;
      }
      case SCALE_UP: {
        Vectors v1{Vectors::set(1)};
        std::cout << "Enter scaling factor: ";
        double factor{};
        std::cin >> factor;
        Vectors::print(v1.mul(factor), "Scaled vector");
        holdResult();
        break;
      }
      case EQUALITY_CHECK: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        std::cout << std::boolalpha;
        std::cout << "Vectors are equal: " << (v1 == v2) << "\n";
        holdResult();
        break;
      }
      case MAGNITUDE: {
        Vectors v1{Vectors::set(1)};
        std::cout << "Magnitude: " << v1.mag() << "\n";
        holdResult();
        break;
      }
      case ANGLE_RADIANS: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        std::cout << "Angle (rads): " << v1.angleR(v2) << "\n";
        holdResult();
        break;
      }
      case ANGLE_DEGREES: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        std::cout << "Angle (degs): " << v1.angleD(v2) << "\n";
        holdResult();
        break;
      }
      case CLAMP: {
        Vectors v1{Vectors::set(1)};
        std::cout << "Enter magnitude to clamp to: ";
        double clamp{};
        std::cin >> clamp;
        Vectors::print(v1.resizeTo(clamp), "Clamped vector");
        holdResult();
        break;
      }
      case PROJECTION: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        Vectors::print(v1.componentAlong(v2), "Projection of 1 along 2");
        holdResult();
        break;
      }
      case DISTANCE: {
        Vectors v1{Vectors::set(1)};
        Vectors v2{Vectors::set(2)};
        std::cout << "Distance: " << v1.distanceBetween(v2) << "\n";
        holdResult();
        break;
      }
      default:
        std::cout << "Invalid function...\n";
        appRunning = false;
    }
  }

  return 0;
}
