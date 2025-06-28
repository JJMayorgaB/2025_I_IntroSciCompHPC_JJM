CXX = g++
CXXFLAGS = -std=c++17 -O3 -Wall -Wextra -fopenmp
TARGET = parallel_metrics.x
SOURCE = parallel_metrics.cpp

# Detectar si TBB está disponible
TBB_AVAILABLE := $(shell pkg-config --exists tbb && echo "yes" || echo "no")

ifeq ($(TBB_AVAILABLE),yes)
    CXXFLAGS += -DTBB_AVAILABLE
    LDFLAGS += $(shell pkg-config --libs tbb)
endif

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE) $(LDFLAGS)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	@echo "Running test with small vector..."
	./$(TARGET) 1000000 4 2
	@echo "\nRunning test with different thread counts..."
	./$(TARGET) 5000000 1 1
	./$(TARGET) 5000000 2 1
	./$(TARGET) 5000000 4 1
	./$(TARGET) 5000000 8 1

benchmark: $(TARGET)
	@echo "Running comprehensive benchmark..."
	@echo "Vector size: 10,000,000 elements"
	@for threads in 1 2 4 8; do \
		echo "--- Testing with $$threads threads ---"; \
		./$(TARGET) 10000000 $$threads 2; \
		echo; \
	done

.PHONY: clean test benchmark