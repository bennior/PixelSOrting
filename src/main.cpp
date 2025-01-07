#include "QuickSort.hpp"
#include "Image.hpp"
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
    // int width = 0, height = 0, channels = 0;

    // char* img = (char*) stbi_load("res/nature.png", &width, &height, &channels, 3);
    // stbi_write_png("output.png", width, height, 3, img, width * 3);

  Pixel** pixels = o_load_image("res/nature.png");
o_write_image(pixels, "output_image.png");
}