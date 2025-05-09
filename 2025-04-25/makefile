# Makefile para generación de PDFs de distribución normal

# Compilador y opciones
CXX := g++
CXXFLAGS := -std=c++17 -Wall -O3
PYTHON := python

# Nombres de archivos
TARGET := random_pdf
SOURCE := random_pdf.cpp
PYSCRIPT := grafica.py
DATA_FILES := datos1.txt datos2.txt datos3.txt
PDF_OUTPUT := random_pdf_plot.pdf

# Parámetros de ejecución
SAMPLES := 5000
MU := 3.5
SIGMA := 0.4
XMIN := 2.7
XMAX := 4.6
BINS := 50
SEEDS := 1 2 5

.PHONY: all clean run plot

all: $(PDF_OUTPUT)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $< -o $@

$(DATA_FILES): $(TARGET)
	@echo "Generando datos con diferentes semillas..."
	./$(TARGET) 1 $(SAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(BINS) > datos1.txt
	./$(TARGET) 2 $(SAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(BINS) > datos2.txt
	./$(TARGET) 5 $(SAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(BINS) > datos3.txt

$(PDF_OUTPUT): $(DATA_FILES) $(PYSCRIPT)
	@echo "Generando gráfico..."
	$(PYTHON) $(PYSCRIPT)
	@echo "Gráfico generado: $(PDF_OUTPUT)"

run: $(TARGET)
	@echo "Ejecutando el programa con semillas 1, 2 y 5..."
	./$(TARGET) 1 $(SAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(BINS) > datos1.txt
	./$(TARGET) 2 $(SAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(BINS) > datos2.txt
	./$(TARGET) 5 $(SAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(BINS) > datos3.txt

plot: $(PDF_OUTPUT)

clean:
	rm -f $(TARGET) $(DATA_FILES) $(PDF_OUTPUT)