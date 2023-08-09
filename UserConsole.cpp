#include "UserConsole.h"
#include "RandomNumberGenerator.h"
#include "SortingTimer.h"
#include "SortingTimeManager.h"
#include <iostream>

UserConsole::UserConsole() {
    min_ = 1;
    max_ = 100;
    number_ = 30;
    number_of_sets_ = 1;

    // Instantiate sorting algorithm classes
    sortingAlgorithms_.push_back(new SelectionSort);
    sortingAlgorithms_.push_back(new BubbleSort);
    sortingAlgorithms_.push_back(new InsertionSort);
    sortingAlgorithms_.push_back(new MergeSort);
    sortingAlgorithms_.push_back(new QuickSort);
    sortingAlgorithms_.push_back(new HeapSort);
    sortingAlgorithms_.push_back(new CountingSort);
    sortingAlgorithms_.push_back(new RadixSort);
}

void UserConsole::run() {
    std::cout << "Welcome to Sorting Algorithm Test!" << std::endl;

    min_ = getIntegerInput("Enter the minimum value for random numbers: ");
    max_ = getIntegerInput("Enter the maximum value for random numbers: ");
    number_ = getIntegerInput("Enter the number of elements in each set: ");
    number_of_sets_ = getIntegerInput("Enter the number of sets: ");

    // Instantiate random number generator
    RandomNumberGenerator rng(min_, max_, number_, number_of_sets_);

    std::vector<std::vector<int>> sets = rng.generateRandomSets();

    SortingTimeManager timeManager;

    displaySortingAlgorithms();
    std::vector<int> chosenAlgorithms = chooseAlgorithms();

    for (const auto& set : sets) {
        std::cout << "Original Set: ";
        for (int num : set) {
            std::cout << num << " ";
        }
        std::cout << "\n";

        for (int choice : chosenAlgorithms) {
            Sort* algorithm = sortingAlgorithms_[choice];
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
}

int UserConsole::getIntegerInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}

void UserConsole::displaySortingAlgorithms() {
    std::cout << "Available Sorting Algorithms:" << std::endl;
    for (int i = 0; i < sortingAlgorithms_.size(); ++i) {
        std::cout << i + 1 << ". " << sortingAlgorithms_[i]->getName() << std::endl;
    }
}

std::vector<int> UserConsole::chooseAlgorithms() {
    std::vector<int> chosenAlgorithms;

    while (true) {
        int choice = getIntegerInput("Enter the number of the algorithm to test (0 to finish): ");

        if (choice == 0) {
            break;
        }

        if (choice >= 1 && choice <= sortingAlgorithms_.size()) {
            chosenAlgorithms.push_back(choice - 1);
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return chosenAlgorithms;
}
