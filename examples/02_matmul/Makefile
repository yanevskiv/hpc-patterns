CXX = g++
CXXFLAGS = -O3 -fdiagnostics-color=always -Wall
TARGET = run-matmul

all: clean $(TARGET)
	@./$(TARGET)

clean:
	@rm -f $(TARGET)

$(TARGET): src/main.cpp
	@$(CXX) $(CXXFLAGS) -o $(@) $(<)
