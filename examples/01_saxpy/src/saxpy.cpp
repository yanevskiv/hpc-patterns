#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <functional>

namespace hpc {

    // (Hand written) Assign random values to a vector
    void uniform_randomize(std::vector<float>& v, int seed = 42)
    {
        std::mt19937 rng(seed);
        std::uniform_real_distribution<float> dist(0.0f, 1.0f);
        for (std::size_t i = 0; i < v.size(); i++) {
            v[i] = dist(rng);
        }
    }

    // (Hand written) Naive implementation of SAXPY: y = a * x + y
    void saxpy(std::vector<float>& y, const std::vector<float>& x, double a)
    {
        const std::size_t N = y.size();
        for (std::size_t i = 0; i < N; i++) {
            y[i] = a * x[i] + y[i];
        }
    }

    // (Hand written) Compute the checksum of a vector
    double checksum(const std::vector<float>& v)
    {
        double checksum = 0.0;
        for (std::size_t i = 0; i < v.size(); i++) {
            checksum += v[i];
        }
        return checksum;
    }

    // (Hand written) Benchmark a function and return the elapsed time
    std::chrono::duration<double> benchmark(std::function<void()> test_func)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test_func();
        auto end = std::chrono::high_resolution_clock::now();
        return end - start;
    }
}

int main()
{
    // Data
    const std::size_t N = 1 << 24; 
    const float a = 2.5f;
    std::vector<float> x(N);
    std::vector<float> y(N);

    // Initialize data and benchmark
    hpc::uniform_randomize(x);
    hpc::uniform_randomize(y);
    auto elapsed = hpc::benchmark([&](){
        hpc::saxpy(y, x, a);
    });
    double checksum = hpc::checksum(y);

    // Report results
    std::cout << "Elapsed: " << elapsed.count() << "s\n";
    std::cout << "Checksum: " << checksum << "s\n";
    return 0;
}
