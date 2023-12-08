//My Tran - CSCE 350 - Project 1

#include <random>
#include <vector>
#include <fstream>
#include <algorithm>

int main() {
    std::random_device rd;  // Random number device
    std::mt19937 generator(rd()); // Mersenne twister generator
    std::uniform_real_distribution<> distribution(-100.0, 100.0); // Uniform distribution

    for (int size = 10; size <= 1000; size *= 10) {
        for (int i = 0; i < 25; ++i) {
            std::ofstream file("input" + std::to_string(size) + "_" + std::to_string(i) + ".txt");
            std::vector<float> numbers;
            while (numbers.size() < size) {
                numbers.push_back(distribution(generator));
            }
            // Shuffle the numbers to ensure they are unsorted
            std::shuffle(numbers.begin(), numbers.end(), generator);
            for (const auto& num : numbers) {
                file << num << " ";
            }
            file << "\n";
        }
    }

    return 0;
}

