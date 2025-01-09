#include "quicksort.hpp"
#include "image.hpp"
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
    Image image;
    {
    Timer timer;
    load_image(image, "res/nature.png"); 
    write_image(image, "res/output_nature.png");
    }
}