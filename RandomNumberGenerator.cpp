// RandomNumberGenerator.cpp
#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(int min, int max, int number, int number_of_set)
    : min_(min), max_(max), number_(number), number_of_set_(number_of_set), gen_(rd_()) {
}

std::vector<std::vector<int>> RandomNumberGenerator::generateRandomSets() {
    std::uniform_int_distribution<> dis(min_, max_);

    std::vector<std::vector<int>> result;

    for (int setIndex = 0; setIndex < number_of_set_; ++setIndex) {
        std::vector<int> currentSet;
        for (int i = 0; i < number_; ++i) {
            currentSet.push_back(dis(gen_));
        }
        result.push_back(currentSet);
    }

    return std::move(result);
}
