#include <vector>
#include "SortingAlgorithms.h"
void Sort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort::sort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(array[i], array[minIndex]);
        }
    }
}

void BubbleSort::sort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void InsertionSort::sort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void MergeSort::sort(std::vector<int>& array) {
    mergeSortRecursive(array, 0, array.size() - 1);
}

void MergeSort::merge(std::vector<int>& array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; ++i) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            ++i;
        } else {
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void MergeSort::mergeSortRecursive(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSortRecursive(array, left, middle);
        mergeSortRecursive(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void QuickSort::sort(std::vector<int>& array) {
    quickSortRecursive(array, 0, array.size() - 1);
}

void QuickSort::quickSortRecursive(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(array, left, right);
        quickSortRecursive(array, left, pivotIndex - 1);
        quickSortRecursive(array, pivotIndex + 1, right);
    }
}

int QuickSort::partition(std::vector<int>& array, int left, int right) {
    int pivot = array[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; ++j) {
        if (array[j] < pivot) {
            ++i;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[right]);
    return i + 1;
}

void HeapSort::sort(std::vector<int>& array) {
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(array, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void HeapSort::heapify(std::vector<int>& array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}
void CountingSort::sort(std::vector<int>& array) {
    int maxVal = *std::max_element(array.begin(), array.end()) + 1;
    std::vector<int> count(maxVal, 0);
    std::vector<int> output(array.size());

    for (int num : array) {
        ++count[num];
    }

    for (int i = 1; i < maxVal; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; --i) {
        output[count[array[i]] - 1] = array[i];
        --count[array[i]];
    }

    array = output;
}


void RadixSort::sort(std::vector<int>& array) {
    int maxVal = getMax(array, array.size());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortRadix(array, array.size(), exp);
    }
}

int RadixSort::getMax(std::vector<int>& array, int n) {
    int maxVal = array[0];
    for (int i = 1; i < n; ++i) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}

void RadixSort::countingSortRadix(std::vector<int>& array, int n, int exp) {
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; ++i) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i) {
        array[i] = output[i];
    }
}

#include "SortingAlgorithms.h"

// For SelectionSort
std::string SelectionSort::getName() const {
    return "SelectionSort";
}

// For BubbleSort
std::string BubbleSort::getName() const {
    return "BubbleSort";
}

// For InsertionSort
std::string InsertionSort::getName() const {
    return "InsertionSort";
}

// For MergeSort
std::string MergeSort::getName() const {
    return "MergeSort";
}

// For QuickSort
std::string QuickSort::getName() const {
    return "QuickSort";
}

// For HeapSort
std::string HeapSort::getName() const {
    return "HeapSort";
}

// For CountingSort
std::string CountingSort::getName() const {
    return "CountingSort";
}

// For RadixSort
std::string RadixSort::getName() const {
    return "RadixSort";
}
