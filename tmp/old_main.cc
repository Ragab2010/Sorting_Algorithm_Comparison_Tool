#include <iostream>
#include <vector>
#include "SortingAlgorithms.h"
#include "RandomNumberGenerator.h"
#include "SortingTimer.h"
#include "SortingTimeManager.h"

int main() {
    const int min = 1;
    const int max = 100;
    const int number = 30; // Increase input size
    const int number_of_sets = 2;

    // Instantiate random number generator
    RandomNumberGenerator rng(min, max, number, number_of_sets);

    std::vector<std::vector<int>> sets = rng.generateRandomSets();

    // Instantiate sorting algorithm classes
    SelectionSort selectionSort;
    BubbleSort bubbleSort;
    InsertionSort insertionSort;
    MergeSort mergeSort;
    QuickSort quickSort;
    HeapSort heapSort;
    CountingSort countingSort;
    RadixSort radixSort;

    // Create an array of pointers to the sorting algorithms
    Sort* sortingAlgorithms[] = {
        &selectionSort, &bubbleSort, &insertionSort,
        &mergeSort, &quickSort, &heapSort,
        &countingSort, &radixSort
    };

    // Create a SortingTimeManager instance
    SortingTimeManager timeManager;

    for (const auto& set : sets) {
        std::cout << "Original Set: ";
        for (int num : set) {
            std::cout << num << " ";
        }
        std::cout << "\n";

        for (Sort* algorithm : sortingAlgorithms) {
            std::vector<int> sortedSet = set;

            timeManager.startTimerForAlgorithm(algorithm->getName());
            algorithm->sort(sortedSet);
            timeManager.stopTimerForAlgorithm(algorithm->getName());
            
            std::cout << algorithm->getName() << " Sorted Set: ";
            for (int num : sortedSet) {
                std::cout << num << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\n";
    }

    std::cout << "\nSorting Algorithm Times:\n";
    timeManager.printSortedTimes();

    return 0;
}
