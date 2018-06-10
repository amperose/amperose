#ifndef RGB_LED_H
#define RGB_LED_H

#include <stdint.h>

// Define the hexadecimal value of rainbow colors
#define RGB_LED_RED    0xFF0000
#define RGB_LED_ORANGE 0xFF7F00
#define RGB_LED_YELLOW 0xFFFF00
#define RGB_LED_GREEN  0x00FF00
#define RGB_LED_BLUE   0x0000FF
#define RGB_LED_INDIGO 0x4B0082
#define RGB_LED_VIOLET 0x9400D3

// Initialization of RGB LED
void RGB_Led_Init(void);

// Update the color of RGB LED given the R-G-B components
void RGB_Led_Update_Color(uint8_t r, uint8_t g, uint8_t b);

// Update the color of RGB LED given the hex value of the color
void RGB_Led_Update_Color_Hex(uint32_t c);

#endif
