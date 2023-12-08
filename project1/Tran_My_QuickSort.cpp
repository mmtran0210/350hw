//My Tran - CSCE 350 - Project 1

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

// perform QuickSort and record execution time to ExecutionData.txt
void doQuickSort(const char* inputFile, const char* outputFile, const char* timeFile) {
    std::ifstream input(inputFile);
    std::ofstream output(std::string(outputFile) + ".txt");
    std::ofstream timeOutput(timeFile, std::ios_base::app); // ExecutionData.txt append
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

    // Write data to ExecutionData.txt
    timeOutput << arr.size() << "    " << duration.count() << "\n";

    // Write sorted array after quicksort to output file
    for (const auto& value : arr)
        output << value << " ";
}

void writeExecutionFile(const char* unformattedTimeFile, const char* formattedTimeFile) {
    std::ifstream timeInput(unformattedTimeFile);
    std::ofstream formattedTimeOutput(formattedTimeFile);
    int size;
    long long time;

    // Construct the table
    formattedTimeOutput << std::left << std::setw(12) << "Input Size" << " || " << std::setw(25) << " Execution Time (in milliesecond)" << "\n";
    formattedTimeOutput << std::string(40, '-') << "\n"; // Separator line

    // Read times from data file and write in a table
    while (timeInput >> size >> time) {
        formattedTimeOutput << std::left << std::setw(12) << size << " || " << std::setw(25) << std::scientific << std::setprecision(4) << time << "\n";
    }
}

void writeAverageTimesFile(const char* timeFile, const char* avgTimeFile) {
    std::ifstream timeInput(timeFile);
    std::ofstream avgTimeOutput(avgTimeFile);
    std::map<int, std::vector<long long>> executionTimes; // map input size to their execution times vector
    int size;
    long long time;

    // Read execution times from file
    while (timeInput >> size >> time) {
        executionTimes[size].push_back(time);
    }

    // Table
    avgTimeOutput << std::left << std::setw(12) << "Input Size" << " || " << std::setw(25) << " Average Execution Time (in milliesecond)" << "\n";
    avgTimeOutput << std::string(40, '-') << "\n"; // Separator line

    // Compute average times and write to file
    for (const auto& pair : executionTimes) {
        long long sum = std::accumulate(pair.second.begin(), pair.second.end(), 0LL);
        long long avgTime = sum / pair.second.size();
        avgTimeOutput << std::left << std::setw(12) << pair.first << " || " << std::setw(25) << std::scientific << std::setprecision(4) << avgTime << "\n";
    }
}

int main(int argc, char* argv[]) {
    // Perform QuickSort and record execution time for each input size
    doQuickSort(argv[1], argv[2], argv[3]);

    // After all input files have been sorted, parse the times collected in ExecutionData.txt to compute average times and write to file
    writeAverageTimesFile(argv[3], "Tran_My_averageExecutionTime.txt");

    // Format the execution times collected in ExecutionData.txt into a table
    writeExecutionFile(argv[3], "Tran_My_executionTime.txt");

    return 0;
}


