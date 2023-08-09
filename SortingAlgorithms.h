#pragma once

#include <vector>
#include <algorithm>
#include <string>

class Sort {
public:
    virtual void sort(std::vector<int>& array) = 0;
    virtual std::string getName() const = 0; // Add getName() method

protected:
    void swap(int& a, int& b);
};

class SelectionSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method
};

class BubbleSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method
};

class InsertionSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method
};

class MergeSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method

private:
    void merge(std::vector<int>& array, int left, int middle, int right);
    void mergeSortRecursive(std::vector<int>& array, int left, int right);
};

class QuickSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method

private:
    void quickSortRecursive(std::vector<int>& array, int left, int right);
    int partition(std::vector<int>& array, int left, int right);
};

class HeapSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method

private:
    void heapify(std::vector<int>& array, int n, int i);
};

class CountingSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method

private:
    void countingSortRadix(std::vector<int>& array, int n, int exp);
};

class RadixSort : public Sort {
public:
    void sort(std::vector<int>& array) override;
    std::string getName() const override; // Implement getName() method

private:
    int getMax(std::vector<int>& array, int n);
    void countingSortRadix(std::vector<int>& array, int n, int exp);
};
