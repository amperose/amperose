#include "board.h"
#include "rgb_led.h"
#include "stm32f7xx_hal.h"

// Define TIM_HandleTypeDef structure (Global definition of TIM4)
TIM_HandleTypeDef PWM4_Struct;

// Define TIM_OC_InitTypeDef structure (Channel definitions)
TIM_OC_InitTypeDef Channel_Config_Struct;

// Private function for TIM4 PWM Initialization
void PWM_TIM4_Init(void) {
  // Register Base Address
  PWM4_Struct.Instance = TIM4;

  // TIM Time Base required parameters
  PWM4_Struct.Init.Prescaler = 0;
  PWM4_Struct.Init.CounterMode = TIM_COUNTERMODE_UP;
  PWM4_Struct.Init.Period = 100000;
  PWM4_Struct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

  // Initialize TIM4 using the STM32 HAL Function
  HAL_TIM_PWM_Init(&PWM4_Struct);

  // TIM4 Clock Enable
  __TIM4_CLK_ENABLE();

  // Start PWM
  HAL_TIM_PWM_Start(&PWM4_Struct, TIM_CHANNEL_2|TIM_CHANNEL_3|TIM_CHANNEL_4);
}

// Initialization of RGB LED
void RGB_Led_Init(void) {
  // Define the GPIO configuration struct
  // This struct defines Pin, Mode, Pull (Up/Down), Speed & Alternate Function
  GPIO_InitTypeDef RGB_LED_InitStruct;

  // Define Common Configuration for the 3 Pins (R-G-B)
  // Alternate Function Push Pull
  RGB_LED_InitStruct.Mode = GPIO_MODE_AF_PP;

  // No Pull Up / Pull Down
  RGB_LED_InitStruct.Pull = GPIO_NOPULL;

  // Highest Speed
  RGB_LED_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // Alternate Function 2 (Timer 4)
  RGB_LED_InitStruct.Alternate = GPIO_AF2_TIM4;

  // Configure Line RGB_R
  RGB_LED_InitStruct.Pin = RGB_R_PIN;
  HAL_GPIO_Init(RGB_R_GPIO, &RGB_LED_InitStruct);

  // Configure Line RGB_G
  RGB_LED_InitStruct.Pin = RGB_G_PIN;
  HAL_GPIO_Init(RGB_G_GPIO, &RGB_LED_InitStruct);

  // Configure Line RGB_B
  RGB_LED_InitStruct.Pin = RGB_B_PIN;
  HAL_GPIO_Init(RGB_B_GPIO, &RGB_LED_InitStruct);

  // RGB LED uses TIM4 PWM ==> Configure TIM4
  PWM_TIM4_Init();

  // Turn on a color (Blue is my Fav)
  RGB_Led_Update_Color_Hex(RGB_LED_BLUE);
}

// Update the color of RGB LED given the R-G-B components
void RGB_Led_Update_Color(uint8_t r, uint8_t g, uint8_t b) {
  // Channel configuration
  Channel_Config_Struct.OCMode = TIM_OCMODE_PWM1;
  Channel_Config_Struct.OCIdleState = TIM_OCIDLESTATE_SET;
  Channel_Config_Struct.OCPolarity = TIM_OCPOLARITY_LOW;
  Channel_Config_Struct.OCFastMode = TIM_OCFAST_ENABLE;

  // Channel R
  Channel_Config_Struct.Pulse = (r & 0xFF) << 1;
  HAL_TIM_PWM_ConfigChannel(&PWM4_Struct, &Channel_Config_Struct, TIM_CHANNEL_2);

  // Channel G
  Channel_Config_Struct.Pulse = (g & 0xFF) << 1;
  HAL_TIM_PWM_ConfigChannel(&PWM4_Struct, &Channel_Config_Struct, TIM_CHANNEL_3);

  // Channel B
  Channel_Config_Struct.Pulse = (b & 0xFF) << 1;
  HAL_TIM_PWM_ConfigChannel(&PWM4_Struct, &Channel_Config_Struct, TIM_CHANNEL_4);
}

// Update the color of RGB LED given the hex value of the color
void RGB_Led_Update_Color_Hex(uint32_t c) {
  // Call the previous function with corresponding parameters
  RGB_Led_Update_Color((c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF);
}
