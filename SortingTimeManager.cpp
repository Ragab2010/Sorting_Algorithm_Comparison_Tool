#include "SortingTimeManager.h"
#include <algorithm>
#include <iostream>

void SortingTimeManager::startTimerForAlgorithm(const std::string& algorithmName) {
   // timer(algorithmName);
    timer.startTimer();
}

void SortingTimeManager::stopTimerForAlgorithm(const std::string& algorithmName) {
    //timer(algorithmName);
    timer.stopTimer();
    long long duration = timer.getDuration(); // Assuming SortingTimer has a getDuration() method
    results_.emplace_back(algorithmName, duration);
    timer.printTime(algorithmName);
}

void SortingTimeManager::printSortedTimes() const {
    std::vector<AlgorithmResult> sortedResults = results_;
    std::sort(sortedResults.begin(), sortedResults.end(), [](const AlgorithmResult& a, const AlgorithmResult& b) {
        return a.duration < b.duration;
    });

    for (const AlgorithmResult& result : sortedResults) {
        std::cout << result.name << " took " << result.duration << " microseconds." << std::endl;
    }
}
