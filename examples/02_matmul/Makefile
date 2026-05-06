CXX = g++
CXXFLAGS = -O3 -fdiagnostics-color=always -Wall -Iinclude
TARGET = run-matmul

all: $(TARGET)
	@./$(TARGET)

clean:
	@rm -f $(TARGET)

$(TARGET): src/main.cpp
	@$(CXX) $(CXXFLAGS) -o $(@) $(<)

