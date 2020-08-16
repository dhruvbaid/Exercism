#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum
{
    BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
} resistor_band_t;

unsigned char color_code(resistor_band_t col);

unsigned int* colors();

#endif
