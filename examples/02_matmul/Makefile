CXX = g++
CXXFLAGS = -O3 -fdiagnostics-color=always -Wall -Iinclude -fopenmp
TARGET = run-matmul
TIMEOUT = 0.5

# Run recipe
run: $(TARGET)
	@timeout $(TIMEOUT) ./$(TARGET)

# Cleanup recipe
clean:
	@rm -f $(TARGET)

# Target recipe
$(TARGET): src/main.cpp include/hpc/Benchmark.hpp include/hpc/Matrix.hpp include/hpc/algorithm/Matrix.hpp
	@$(CXX) $(CXXFLAGS) -o $(@) $(<)

# Phony recipes
.PHONY: run clean
