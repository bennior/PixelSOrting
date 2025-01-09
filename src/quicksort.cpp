#include "quicksort.hpp"
#include "image.hpp"
#include <utility>
#include <cstdlib>
#include <ctime>

void partition(int* array, int low, int high, Pixel* pixels) {
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
            std::swap(pixels[i], pixels[j]);
            i++;
            j--;
        }
    }

    if(j > low)
        partition(array, low, j, pixels);
    if(i < high) {
        partition(array, i, high, pixels);
    }
}

void quicksort(int* array, int length, Pixel* pixels) {
    partition(array, 0, length - 1, pixels);
}

