#ifndef USER_CONSOLE_H
#define USER_CONSOLE_H

#include <vector>
#include "SortingAlgorithms.h"

class UserConsole {
public:
    UserConsole();

    void run();

private:
    int getIntegerInput(const std::string& prompt);
    void displaySortingAlgorithms();
    std::vector<int> chooseAlgorithms();

    int min_;
    int max_;
    int number_;
    int number_of_sets_;
    std::vector<Sort*> sortingAlgorithms_;
};

#endif // USER_CONSOLE_H
