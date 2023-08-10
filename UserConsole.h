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

    int min_{1};
    int max_{99};
    int number_{30};
    int number_of_sets_{1};
    std::vector<Sort*> sortingAlgorithms_;
};

#endif // USER_CONSOLE_H
