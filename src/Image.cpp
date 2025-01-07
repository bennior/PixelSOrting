#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include "Image.hpp"
#include <iostream>

Pixel** o_load_image(char* image) {
    int width = 0, height = 0, actual_channels = 0, channels = 3;

    char* img = (char*) stbi_load(image, &width, &height, &actual_channels, channels);

    if(!img) {
        std::cout << "Error in loading the image\n";
        exit(1);
    }

    
    Pixel** pixels = new Pixel*[height];
    for(int p = 0; p < height; p++)
        pixels[p] = new Pixel[width];

    int channel_count = 0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixels[i][j].red = *(img + channel_count); 
            pixels[i][j].green = *(img + channel_count + 1);
            pixels[i][j].blue = *(img + channel_count + 2);
            pixels[i][j].sorting_value = 0;

            channel_count += channels;
        }
    }
return pixels;
}

void o_write_image(Pixel** pixels, char* output_file) {
    // int height = sizeof(pixels) / sizeof(pixels[0]);
    // int width = sizeof(pixels[0]) / sizeof(char); 
    int height = 880, width = 880;
    int channels = 3;
    char* img = new char[channels * width * height];

    int channel_count = 0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            *(img + channel_count) = pixels[i][j].red;
            *(img + channel_count + 1) = pixels[i][j].green;
            *(img + channel_count + 2) = pixels[i][j].blue;

            channel_count += channels;
        }
    }

    stbi_write_png(output_file, width, height, channels, img, width * channels);
}
