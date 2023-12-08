## My Tran - CSCE 350 - Project 1

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
OUTPUTS = $(patsubst input%,output%,$(INPUTS:.txt=.txt))

# Execution time file
EXEC_TIME_FILE = ExecutionTime_Data.txt

# Input Generator file
INPUT_GENERATOR = InputFileGenerator

# Average execution time file
AVG_EXEC_TIME_FILE = Tran_My_AverageExecutionTime.txt

# Formatted execution time file
FORMATTED_EXEC_TIME_FILE = Tran_My_ExecutionTime.txt

all: $(TARGET) $(OUTPUTS)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

output%.txt: input%.txt $(TARGET)
	./$(TARGET) $< $@ $(EXEC_TIME_FILE)

clean:
	-rm -f $(TARGET) $(INPUTS) $(OUTPUTS) $(EXEC_TIME_FILE) $(AVG_EXEC_TIME_FILE) $(FORMATTED_EXEC_TIME_FILE) $(INPUT_GENERATOR)
