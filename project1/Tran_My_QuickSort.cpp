#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <iomanip>

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

void doQuickSort(const char* inputFile, const char* outputFile, const char* timeFile, const char* avgTimeFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);
    std::ofstream timeOutput(timeFile, std::ios_base::app); // Open in append mode
    std::ofstream avgTimeOutput(avgTimeFile, std::ios_base::app); // Open in append mode
    std::vector<float> arr;
    std::vector<long long> times;
    float num;

    // Read numbers from file
    while (input >> num)
        arr.push_back(num);

    // Create a copy of the original unsorted array
    std::vector<float> arrCopy = arr;

    for (int i = 0; i < 25; ++i) {
        // Record start time
        auto start = std::chrono::high_resolution_clock::now();

        // Perform QuickSort on the copy
        quickSort(arrCopy, 0, arrCopy.size() - 1);

        // Record end time
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        times.push_back(duration.count());

        // Write input size and execution time to time file
        timeOutput << std::setw(10) << arr.size() << "    " << std::setprecision(2) << std::scientific << static_cast<double>(duration.count()) << "\n";

        std::cout << "Time taken by QuickSort: " << std::setprecision(2) << std::scientific << duration.count() << " microseconds" << std::endl;
    }

    // Write sorted numbers to output file
    for (std::vector<float>::size_type i = 0; i < arrCopy.size(); i++)
        output << arrCopy[i] << " ";

    // Compute average execution time
    long long sum = std::accumulate(times.begin(), times.end(), 0LL);
    long long avgTime = sum / times.size();

    // Write input size and average execution time to average time file
    avgTimeOutput << std::setw(10) << arr.size() << "    " << std::setprecision(2) << std::scientific << static_cast<double>(avgTime) << "\n";
}


int main(int argc, char* argv[]) {
    
    doQuickSort(argv[1], argv[2], "Tran_My_executionTime.txt", "Tran_My_averageExecutionTime.txt");
    return 0;
}


