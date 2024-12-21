#include "QuickSort.hpp"
#include <utility>
#include <cstdlib>
#include <ctime>

void quicksort(int* array, int length) {
    partition(array, 0, length - 1);
}

void partition(int* array, int low, int high) {
    int i = low;
    int j = high;
    int pivot_index = high;
    int pivot = array[pivot_index];

    while(i <= j) {
        while(array[i] < pivot) 
            i++;
        while(array[j] > pivot)
            j--;
        if(i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if(j > low)
        partition(array, low, j);
    if(i < high) {
        partition(array, i, high);
    }
}
