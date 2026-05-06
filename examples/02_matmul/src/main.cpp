// Author: Ivan Janevski

#include <iostream>
#include <hpc/Matrix.hpp>
#include <hpc/Benchmark.hpp>
#include <hpc/algorithm/Matrix.hpp>

int main()
{
    const std::size_t N = 550;
	hpc::Matrix matrix_1(N, N);
	hpc::Matrix matrix_2(N, N);

    hpc::Benchmark("MATMUL_ACCEL_NONE", [&](){
        hpc::algorithm::MatMul(matrix_1, matrix_2, hpc::algorithm::MATMUL_ACCEL_NONE);
    });
    hpc::Benchmark("MATMUL_ACCEL_OPENMP", [&](){
        hpc::algorithm::MatMul(matrix_1, matrix_2, hpc::algorithm::MATMUL_ACCEL_OPENMP);
    });
	return 0;
}
