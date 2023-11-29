#include <fstream>
#include <random>
#include <set>

int main() {
    std::random_device rd;  // Random number device
    std::mt19937 generator(rd()); // Mersenne twister generator
    std::uniform_real_distribution<> distribution(-100.0, 100.0); // Uniform distribution

    for (int size = 10; size <= 1000; size *= 10) {
        for (int i = 0; i < 25; ++i) {
            std::ofstream file("input" + std::to_string(size) + "_" + std::to_string(i) + ".txt");
            std::set<float> numbers;
            while (numbers.size() < size) {
                numbers.insert(distribution(generator));
            }
            for (const auto& num : numbers) {
                file << num << "\n";
            }
        }
    }

    return 0;
}
