# Matmul

**Matmul** is an algorithm in high-performance computing (HPC). It is a BLAS level 2 ("Basic Linear Algebra Subprograms") algorithm.

## Definition
### Matrices
Let $\mathbf A\in\mathbb{R}^{A_\text{rows}\times A_\text{cols}}$ and $\mathbf B\in \mathbb R^{B_\text{rows}\times B_\text{cols}}$ be square matrices over real numbers and let $A_\text{rows} = B_\text{cols}$.

Matmul defined as a matrix multiplication $\mathbf A\cdot \mathbf B$ that results in matrix $\mathbf C\in\mathbb{R}^{A_\text{rows}\times B_\text{cols}}$.

$$ \mathbf {C} = \mathbf{A}\cdot \mathbf {B}$$

## Implementation
```c++
Matrix MatMul(const Matrix& a, const Matrix& b)
{
    const std::size_t i_max = a.rows();
    const std::size_t j_max = b.cols();
    const std::size_t k_max = a.cols();
    Matrix c(i_max, j_max);
    for (std::size_t i = 0; i < i_max; i++) {
        for (std::size_t j = 0; j < j_max; j++) {
            for (std::size_t k = 0; k < k_max; k++) {
                c(i, j) += a(i, k) * b(k, j);
            }
        }
    }
}
```