#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include "image.hpp"
#include "quicksort.hpp"
#include "image_utility.hpp"
#include <iostream>

void load_image(Image& __image, char* __file_name) {
    int desired_channels = 3;

    char* img = (char*) stbi_load(__file_name, &__image.width, &__image.height, &__image.channels, desired_channels);

    if(!__file_name) {
        std::cout << "Error in loading the image\n";
        exit(1);
    }

    __image.pixels = new Pixel*[__image.height];
    for(int z = 0; z < __image.height; z++)
        __image.pixels[z] = new Pixel[__image.width];

    char* p = img;
    for(int i = 0; i < __image.height; i++) {
        for(int j = 0; j < __image.width; j++) {
            __image.pixels[i][j].red = *(p); 
            __image.pixels[i][j].green = *(p + 1);
            __image.pixels[i][j].blue = *(p + 2);
            __image.pixels[i][j].sorting_value = get_hue(*p, *(p + 1), *(p + 2));
            p += desired_channels;
        }
    }

    delete[] img;
}

void pixel_sort(Image& __image) {
    for(int i = 0; i < __image.height; i++) {
        int* array = new int[__image.width];
        
        for(int j = 0; j < __image.width; j++)
            array[j] = __image.pixels[i][j].sorting_value;
        
        quicksort(array, __image.width, __image.pixels[i]);

        for(int j = 0; j < __image.width; j++)
            __image.pixels[i][j].sorting_value = array[j];

        delete[] array;
    } 
}

void write_image(Image& __image, char* __file_name) {
    int channels = 3;

    char* img = new char[channels * __image.width * __image.height];

    char* p = img; 
    for(int i = 0; i < __image.height; i++) {
        for(int j = 0; j < __image.width; j++) {
            *(p) = __image.pixels[i][j].red;
            *(p + 1) = __image.pixels[i][j].green;
            *(p + 2) = __image.pixels[i][j].blue;

            p += channels;
        }
    }
        
    stbi_write_png(__file_name, __image.width, __image.height, 3, img, __image.width * channels);

    delete[] img;
}

