#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include "vectors.h"
// // #include <chrono>
#include <iostream>
// #include <print>

/* With no outputs, runtime stats of the program over 1000 runs are as follows:
 * $ python log_averager.py
 * Average: 0.0017058
 * Max: 0.0057
 */

int main()
{
    try {
        auto logger = spdlog::basic_logger_mt("logger",
            "logs/function-call-trace.txt");
        // spdlog::set_level(spdlog::level::debug);
    } catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
    // std::print("Wassup people!, this is {0}", "MineRocker");
    // std::cout << "Hello, world!\n";
    // //    auto t1 = std::chrono::high_resolution_clock::now();
    Vectors v1 {};
    v1.set(1);
    Vectors v2 {};
    v2.set(2);
    Vectors v3 {};
    v3.set(3);
    Vectors v4 { v1 + v2 };
    v4.print("Sum");
    Vectors v5 { v1 - v2 };
    v5.print("Difference");
    Vectors v6 { v1 * v2 };
    v6.print("Cross product");

    Vectors v7 { (v1 * v2) * v3 }; // Vectors::vectorTripleProductL
    v7.print("(v1 x v2) x v3");

    Vectors v8 { v1 * (v2 * v3) }; // Vectors::vectorTripleProductR
    v8.print("v1 x (v2 x v3)");
    // v1.dot(v2);
    std::cout << "Dot product: " << v1.dot(v2) << "\n";
    std::cout << "Scalar triple product: " << (v1 * v2).dot(v3) << std::endl;

    Vectors v9 { v1.componentAlong(v2) };
    v9.print("Comp of v1 along v2");

    std::cout << "Distance between v1 and v2: "
              << v1.distanceBetween(v2) << "\n";
    // //    auto t2 = std::chrono::high_resolution_clock::now();
    // //    std::chrono::duration<double, std::milli> ms_double = t2 - t1;

    // //    spdlog::get("logger")->info("Time to execute: {}ms", ms_double.count());

    return 0;
}
