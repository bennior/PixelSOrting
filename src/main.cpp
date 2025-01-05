#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

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

    int width, height, channels;
    char* img = (char*) stbi_load("res/nature.png", &width, &height, &channels, 0);

    int i = 0, j = 0;

    if(!img) {
        std::cout << "Error in loading the image\n";
        exit(1);
    }

    // std::cout << "height: " << height << " width: " << width << std::endl;

    int** unsorted_array = new int*[height];
    for(int i = 0; i < height; i++)
        unsorted_array[i] = new int[width];

    //Loop through array
    for(char* p = img; p != img + width * height * channels; p += channels * width) {
        for(char* q = p; q != p + channels * width; q += channels) {
            unsorted_array[i][j] = (int) *(q + 2);
            j++; 
        }
        j = 0;
        i++;
    }

    {
    Timer timer;
        for(int c = 0; c < height; c++) {
            quicksort(&(unsorted_array[c][0]), width);
        }
    }

    char* sorted_array = new char[width * height];

    for(int c = 0; c < height; c++) {
        for(int z = 0; z < width; z++) {
            sorted_array[c * width + z] = (char) unsorted_array[c][z];
        }
    }

    stbi_write_png("output_blue.png", width, height, 1, sorted_array, width);
    
        // quicksort(array, length);
}