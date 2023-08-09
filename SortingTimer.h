#pragma once

#include <chrono>
#include <string>

class SortingTimer {
public:
    // SortingTimer(const std::string& algorithmName);
    SortingTimer();
    void startTimer();
    void stopTimer();
    void printTime(const std::string& algorithmName);
    long long getDuration() const; // New method to get the duration in nanoseconds

private:
    //std::string algorithmName_;
    std::chrono::high_resolution_clock::time_point startTime_;
    std::chrono::high_resolution_clock::time_point endTime_;
    bool isRunning_;
};
