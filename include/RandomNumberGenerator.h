// RandomNumberGenerator.h
#pragma once

#include <vector>
#include <random>

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int min, int max, int number, int number_of_set);

    std::vector<std::vector<int>> generateRandomSets();

private:
    int min_;
    int max_;
    int number_;
    int number_of_set_;
    std::random_device rd_;
    std::mt19937 gen_;
};
