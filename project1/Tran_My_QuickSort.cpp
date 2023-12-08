#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <map>

// the median of three numbers for picking pivot
float medianOfThree(float a, float b, float c) {
    if ((a - b) * (c - a) >= 0)
        return a;
    else if ((b - a) * (c - b) >= 0)
        return b;
    else
        return c;
}

// Partition
int partition(std::vector<float>& arr, int low, int high) {
    float pivot = medianOfThree(arr[low], arr[high], arr[(low + high) / 2]);
    int i = low - 1;

    // Swap the pivot with the last element in the array
    for (int j = low; j <= high; j++) {
        if (arr[j] == pivot) {
            std::swap(arr[j], arr[high]);
            break;
        }
    }

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}


// QuickSort
void quickSort(std::vector<float>& arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

// Function to perform QuickSort and record execution time to ExecutionData.txt
void doQuickSort(const char* inputFile, const char* outputFile, const char* timeFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);
    std::ofstream timeOutput(timeFile, std::ios_base::app); // Open in append mode
    std::vector<float> arr;
    float num;

    // Read numbers from file
    while (input >> num)
        arr.push_back(num);

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Perform QuickSort
    quickSort(arr, 0, arr.size() - 1);

    // Record end time
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Write input size and execution time to time file
    timeOutput << arr.size() << "    " << duration.count() << "\n";

    // Write sorted numbers to output file
    for (const auto& value : arr)
        output << value << " ";
}

// Function to calculate average execution times
void writeAverageTimesFile(const char* timeFile, const char* avgTimeFile) {
    std::ifstream timeInput(timeFile);
    std::ofstream avgTimeOutput(avgTimeFile);
    std::map<int, std::vector<long long>> executionTimes; // map input size to their execution times
    int size;
    long long time;

    // Read execution times from file
    while (timeInput >> size >> time) {
        executionTimes[size].push_back(time);
    }

    // Write headers to the average execution time file
    avgTimeOutput << std::left << std::setw(12) << "Input Size" << " || " << std::setw(25) << " Average Execution Time" << "\n";
    avgTimeOutput << std::string(40, '-') << "\n"; // Separator line

    // Compute and write average execution times in a tabular format
    for (const auto& pair : executionTimes) {
        long long sum = std::accumulate(pair.second.begin(), pair.second.end(), 0LL);
        long long avgTime = sum / pair.second.size();
        avgTimeOutput << std::left << std::setw(12) << pair.first << " || " << std::setw(25) << std::scientific << std::setprecision(2) << avgTime << "\n";
    }
}

void writeExecutionFile(const char* unformattedTimeFile, const char* formattedTimeFile) {
    std::ifstream timeInput(unformattedTimeFile);
    std::ofstream formattedTimeOutput(formattedTimeFile);
    int size;
    long long time;

    // Headers for the formatted time file
    formattedTimeOutput << std::left << std::setw(12) << "Input Size" << " || " << std::setw(25) << " Execution Time" << "\n";
    formattedTimeOutput << std::string(40, '-') << "\n"; // Separator line

    // Read times from data file and write in a table format
    while (timeInput >> size >> time) {
        formattedTimeOutput << std::left << std::setw(12) << size << " || " << std::setw(25) << std::scientific << std::setprecision(2) << time << "\n";
    }
}



int main(int argc, char* argv[]) {
    // Perform QuickSort and record execution time for each input file
    doQuickSort(argv[1], argv[2], argv[3]);

    // After all input files have been processed, calculate average execution times
    writeAverageTimesFile(argv[3], "Tran_My_averageExecutionTime.txt");

    // Format the execution times into a table
    writeExecutionFile(argv[3], "Tran_My_ExecutionTime.txt");

    return 0;
}


