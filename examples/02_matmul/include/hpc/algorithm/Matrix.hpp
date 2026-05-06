// Author: Ivan Janevski

#ifndef __HPC_ALGORITHM_MATMUL_HPP__
#define __HPC_ALGORITHM_MATMUL_HPP__
#include <hpc/Matrix.hpp>
#include <omp.h>

// HPC namespace
namespace hpc
{
	// Algorithm namespace
	namespace algorithm 
	{
		// Set elements of a matrix to zero
		void MatZero(Matrix& m) 
		{
			const std::size_t i_max = m.rows();
			const std::size_t j_max = m.cols();
			for (std::size_t i = 0; i < i_max; i++) {
				for (std::size_t j = 0; j < j_max; j++) {
					m(i, j) = 0.0f;
				}
			}
		}

		// Multiply matrices
        enum MatMulAccel {
            MATMUL_ACCEL_NONE,
            MATMUL_ACCEL_OPENMP
        };
		Matrix MatMul(const Matrix& a, const Matrix& b, MatMulAccel accel_type)
		{
			const std::size_t i_max = a.rows();
			const std::size_t j_max = b.cols();
			const std::size_t k_max = a.cols();
			Matrix c(i_max, j_max);

            switch (accel_type) {
                // Accel: No acceleration
                case MATMUL_ACCEL_NONE: {
                    for (std::size_t i = 0; i < i_max; i++) {
                        for (std::size_t j = 0; j < j_max; j++) {
                            for (std::size_t k = 0; k < k_max; k++) {
                                c(i, j) += a(i, k) * b(k, j);
                            }
                        }
                    }
                } break;

                // Accel: Accelerated using OpenMP
                case MATMUL_ACCEL_OPENMP: {
                    #pragma omp parallel for collapse(2) schedule(static)
                    for (std::size_t i = 0; i < i_max; i++) {
                        for (std::size_t j = 0; j < j_max; j++) {
                            for (std::size_t k = 0; k < k_max; k++) {
                                c(i, j) += a(i, k) * b(k, j);
                            }
                        }
                    }
                } break;
            }
			return c;
		}
	}
}

#endif
