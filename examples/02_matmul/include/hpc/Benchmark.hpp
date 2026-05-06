// Author: Ivan Janevski

#ifndef __HPC_BENCHMARK_HPP__
#define __HPC_BENCHMARK_HPP__
#include <chrono>
#include <iostream>
#include <functional>
#include <string>

namespace hpc
{
    // Benchmark an execution time of a function
    void Benchmark(const std::string& name, std::function<void()> test_func)
    {
        const int n_repeat = 1;
        double duration_mean = 0.0;
        for (int i = 0; i < n_repeat; i++) {
            // Start time
            auto time_start = std::chrono::high_resolution_clock::now();

            // Run function
            test_func();

            // End time
            auto time_end = std::chrono::high_resolution_clock::now();

            // Calculate mean
            std::chrono::duration<double> duration =  time_end - time_start;
            duration_mean += duration.count() / n_repeat;
        }

        // Print
        std::cout << name << ": " << duration_mean * 1000 << " ms\n";
    }
}

#endif
