#include "QuickSort.hpp"
#include <iostream>
#include <chrono>

struct Timer
{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.f;
        std::cout << "Calculation time: " << ms << " ms\n";
    }
};


void print_array(int* array, int length) {
    for(int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {

    int array[] = {93, 12, 45, 86, 72, 31, 54, 21, 37, 77, 64, 58, 9, 26, 68, 17, 99, 43, 78, 81, 59, 61, 88, 36, 56, 57, 49, 92, 82, 29, 3, 51, 27, 60, 4, 66, 22, 74, 19, 47, 90, 75, 71, 63, 7, 70, 23, 28, 38, 80, 50, 73, 41, 53, 5, 10, 11, 79, 24, 30, 46, 25, 20, 35, 83, 55, 34, 85, 65, 14, 18, 67, 39, 76, 40, 15, 16, 84, 1, 48, 2, 8, 32, 33, 13, 69, 52, 18, 94, 95, 98, 30, 98, 41, 95, 29, 87, 66, 100, 93};
    int length = 100;
    
    print_array(array, length);
    {
        Timer timer;
        quicksort(array, length);
    }
    print_array(array, length);
}