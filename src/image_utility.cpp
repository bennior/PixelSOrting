#include "image_utility.hpp"
#include "timer.hpp";
#include <algorithm>

int get_hue(char red, char green, char blue) {
    float R = red / 255.0;    
    float G = green / 255.0;
    float B = blue / 255.0;

    float min = std::min({R, G, B});
    float max = std::max({R, G, B});

    float hue = (max == R) * (G - B) / (max - min) +
                (max == G) * 2.0 + (max == G) * (B - R) / (max - min) + 
                (max == B) * 4.0 + (max == B) * (R - G) / (max - min);       

    hue *= 60.0;
    if (hue < 360) hue += 360.0;

    return (int) hue; 
}