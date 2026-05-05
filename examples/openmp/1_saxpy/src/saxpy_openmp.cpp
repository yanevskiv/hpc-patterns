#include <omp.h>
#include <vector>
#include <random>
#include <chrono>
#include <functional>
#include <iostream>

namespace hpc {
    void uniform_randomize(std::vector<float>& v, int seed = 42)
    {
        std::mt19937 rng(seed);
        std::uniform_real_distribution<float> dist(0.0f, 1.0f);
        const std::size_t N = v.size();
        for (std::size_t i = 0; i < N; i++) {
            v[i] = dist(rng);
        }
    }

    std::chrono::duration<double> benchmark(std::function<void()> test_func)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test_func();
        auto end = std::chrono::high_resolution_clock::now();
        return end - start;
    }

    void saxpy(std::vector<float>& y, const std::vector<float>& x, double a)
    {
        const std::size_t N = y.size();

        #pragma omp parallel for
        for (std::size_t i = 0; i < N; i++) {
            y[i] = a * x[i] + y[i];
        }
    }

}

int main()
{
    const std::size_t N = 1 << 25;
    double a = 2.5f;
    std::vector<float> x(N);
    std::vector<float> y(N);

    hpc::uniform_randomize(x);
    hpc::uniform_randomize(y);
    auto elapsed = hpc::benchmark([&](){
        hpc::saxpy(y, x, a);
    });
    std::cout << "Elapsed: " << elapsed.count() << std::endl;
    return 0;
}
