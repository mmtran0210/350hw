# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Target executable name
TARGET = Tran_My_QuickSort

# Input files
INPUTS = $(wildcard input10_*.txt input100_*.txt input1000_*.txt)

# Output files
OUTPUTS = $(INPUTS:.txt=.out)

all: $(TARGET) $(OUTPUTS)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

%.out: %.txt $(TARGET)
	./$(TARGET) $< $@ "Tran_My_executionTime.txt" "Tran_My_averageExecutionTime.txt"

clean:
	del /F /Q $(TARGET).exe $(OUTPUTS) "Tran_My_executionTime.txt" "Tran_My_averageExecutionTime.txt" $(INPUTS)



