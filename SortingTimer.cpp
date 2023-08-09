#include "SortingTimer.h"
#include <iostream>

//SortingTimer::SortingTimer(const std::string& algorithmName) : algorithmName_(algorithmName), isRunning_(false) {}

SortingTimer::SortingTimer() : isRunning_(false) {}
void SortingTimer::startTimer() {
    if (!isRunning_) {
        startTime_ = std::chrono::high_resolution_clock::now();
        isRunning_ = true;
    }
}

void SortingTimer::stopTimer() {
    if (isRunning_) {
        endTime_ = std::chrono::high_resolution_clock::now();
        isRunning_ = false;
    }
}

void SortingTimer::printTime(const std::string& algorithmName) {
    if (!isRunning_) {
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime_ - startTime_).count();
        std::cout << algorithmName << " took " << duration << " microseconds." << std::endl;
    } else {
        std::cout << algorithmName << " timer is still running." << std::endl;
    }
}

long long SortingTimer::getDuration() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(endTime_ - startTime_).count();
}
