#ifndef SORTING_TIME_MANAGER_H
#define SORTING_TIME_MANAGER_H

#include <string>
#include <vector>
#include "SortingTimer.h"

class SortingTimeManager {
public:
    void startTimerForAlgorithm(const std::string& algorithmName);
    void stopTimerForAlgorithm(const std::string& algorithmName);
    void printSortedTimes() const;

private:
    struct AlgorithmResult {
        std::string name;
        long long duration; // in nanoseconds

        AlgorithmResult(const std::string& n, long long dur) : name(n), duration(dur) {}
    };

    std::vector<AlgorithmResult> results_;
    SortingTimer timer;
};

#endif // SORTING_TIME_MANAGER_H
