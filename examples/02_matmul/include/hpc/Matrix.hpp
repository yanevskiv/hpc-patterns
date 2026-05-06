// Author: Ivan Janevski

#ifndef __HPC_MATRIX_HPP__
#define __HPC_MATRIX_HPP__
#include <vector>

// HPC namespace
namespace hpc
{
	// Matrix
	struct Matrix
	{
	private:
		// Row count
		std::size_t m_rows;

		// Column count
		std::size_t m_cols;

		// Contiguous data (important for HPC!) 
		std::vector<float> m_data;

	public:
		// Constructor
		Matrix(const std::size_t rows, const std::size_t cols)
			: m_rows(rows), m_cols(cols), m_data(rows * cols)
		{
		}

		// Get rows
		std::size_t rows() const { return m_rows; }

		// Get cols
		std::size_t cols() const { return m_cols; }

		// Element operator (const)
		const float& operator()(const std::size_t row, const std::size_t col) const { return m_data[row * m_cols + col]; }

		// Element operator
		float& operator()(const std::size_t row, const std::size_t col) { return m_data[row * m_cols + col]; }
	};
}

#endif
