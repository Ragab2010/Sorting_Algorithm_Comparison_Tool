#include <iostream>
#include <vector>
#include "SortingAlgorithms.h"
#include "RandomNumberGenerator.h"
#include "SortingTimer.h"
#include "SortingTimeManager.h"
#include "UserConsole.h"


int main() {




    UserConsole console;
    console.run();
    return 0;


    // std::cout << "Welcome to Sorting Algorithm Test!" << std::endl;

    // int min, max, number, number_of_sets;
    // std::cout << "Enter the minimum value for random numbers: ";
    // std::cin >> min;

    // std::cout << "Enter the maximum value for random numbers: ";
    // std::cin >> max;

    // std::cout << "Enter the number of elements in each set: ";
    // std::cin >> number;

    // std::cout << "Enter the number of sets: ";
    // std::cin >> number_of_sets;

    // // Instantiate random number generator
    // RandomNumberGenerator rng(min, max, number, number_of_sets);

    // std::vector<std::vector<int>> sets = rng.generateRandomSets();

    // // Instantiate sorting algorithm classes
    // SelectionSort selectionSort;
    // BubbleSort bubbleSort;
    // InsertionSort insertionSort;
    // MergeSort mergeSort;
    // QuickSort quickSort;
    // HeapSort heapSort;
    // CountingSort countingSort;
    // RadixSort radixSort;

    // // Create an array of pointers to the sorting algorithms
    // Sort* sortingAlgorithms[] = {
    //     &selectionSort, &bubbleSort, &insertionSort,
    //     &mergeSort, &quickSort, &heapSort,
    //     &countingSort, &radixSort
    // };

    // // Create a SortingTimeManager instance
    // SortingTimeManager timeManager;

    // std::cout << "Choose algorithms to test:" << std::endl;
    // for (int i = 0; i < sizeof(sortingAlgorithms) / sizeof(sortingAlgorithms[0]); ++i) {
    //     std::cout << i + 1 << ". " << sortingAlgorithms[i]->getName() << std::endl;
    // }

    // std::vector<int> chosenAlgorithms;
    // int choice;
    // while (true) {
    //     std::cout << "Enter the number of the algorithm to test (0 to finish): ";
    //     std::cin >> choice;

    //     if (choice == 0) {
    //         break;
    //     }

    //     if (choice >= 1 && choice <= sizeof(sortingAlgorithms) / sizeof(sortingAlgorithms[0])) {
    //         chosenAlgorithms.push_back(choice - 1);
    //     } else {
    //         std::cout << "Invalid choice. Please try again." << std::endl;
    //     }
    // }

    // for (const auto& set : sets) {
    //     std::cout << "Original Set: ";
    //     for (int num : set) {
    //         std::cout << num << " ";
    //     }
    //     std::cout << "\n";

    //     for (int choice : chosenAlgorithms) {
    //         Sort* algorithm = sortingAlgorithms[choice];
    //         std::vector<int> sortedSet = set;

    //         timeManager.startTimerForAlgorithm(algorithm->getName());
    //         algorithm->sort(sortedSet);
    //         timeManager.stopTimerForAlgorithm(algorithm->getName());

    //         std::cout << algorithm->getName() << " Sorted Set: ";
    //         for (int num : sortedSet) {
    //             std::cout << num << " ";
    //         }
    //         std::cout << "\n";
    //     }

    //     std::cout << "\n";
    // }

    // std::cout << "\nSorting Algorithm Times:\n";
    // timeManager.printSortedTimes();

    return 0;
}
