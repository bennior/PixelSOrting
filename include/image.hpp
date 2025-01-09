#pragma once

typedef struct {
    char red;
    char green;
    char blue;
    char sorting_value;
} Pixel;

typedef struct {
    int width;
    int height;
    int channels;
    Pixel** pixels;                 
} Image;


void load_image(Image& img, char* file_name);
void write_image(Image& img, char* file_name);