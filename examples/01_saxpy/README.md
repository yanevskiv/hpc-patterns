# SAXPY
SAXPY is one of the simplest kernels in HPC. It's a blas primitive of level one. It stands for "sum a times x plus y". Given a real number $a$ and two vectors of same dimension, $y = (y_0, y_1, ..., y_n)$ and $x = (x_0, x_1, ...,x_n)$, 

$\qquad y_{k} = a x_k + y_k$
 

## C++

### SAXPY kernel
The following is a SAXPY kernel written in C++. 
```c++
// #include <vector>

namespace hpc {
    void saxpy(std::vector<float>& y, const std::vector<float>& x, float a) 
    {
        const std::size_t N = y.size();
        for (std::size_t i = 0; i < N; i++) {
            y[i] = a * x[i] + y[i];
        }
    }
}
```
Example:
```c++
// #include <iostream>
// #include <vector>

int main()
{
    // Data
    std::vector<float> x {0.1, 0.1, 0.1};
    std::vector<float> y {0.2, 0.2, 0.2};
    double a = 3;

    // Saxpy
    hpc::saxpy(y, x, a);
    
    // Print: (0.6, 0.6, 0.6)
    for (auto& value : y) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
```
