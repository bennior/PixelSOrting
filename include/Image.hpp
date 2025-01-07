#pragma once

typedef struct {
    char red;
    char green;
    char blue;
    char sorting_value;
} Pixel;

Pixel** o_load_image(char* image);
void o_write_image(Pixel** pixels, char* output);