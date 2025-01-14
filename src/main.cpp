#include "quicksort.hpp"
#include "image.hpp"
#include "timer.hpp"
#include <iostream>

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
    load_image(image, "res/blocks.png"); 
    pixel_sort(image);
    write_image(image, "output_images/blocks_final.png");
    }
}