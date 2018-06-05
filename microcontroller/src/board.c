#include "board.h"
#include "stm32f7xx_hal.h"

// Board Initialization: Set all pins to input floating (Except SWD)
void Board_Init(void) {
  // Define the GPIO configuration struct
  // This struct defines Pin, Mode, Pull (Up/Down), Speed & Alternate Function
  GPIO_InitTypeDef GPIO_InitStruct;

/*********************************** GPIO A ***********************************/

  // GPIOA Setup : All pins will be initialized to floating inputs (except SWD)
  // GPIOA RCC Clock should be enabled
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // PA0-PA12 & PA15: Floating Input
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  // PA0-PA12 & PA15: No Pull Up / Pull Down
  GPIO_InitStruct.Pull = GPIO_NOPULL;

  // PA0-PA12 & PA15: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PA0-PA12 & PA15: We can either apply OR of the 13 pins;
  // or we can use: PIN_All XOR (PIN_14 | PIN_13)
  GPIO_InitStruct.Pin = GPIO_PIN_All ^ (GPIO_PIN_13 | GPIO_PIN_14);

  // Apply the Configuration to GPIOA
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // PA13: Alternate Function Push Pull
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;

  // PA13: Pull Up (SWDIO)
  GPIO_InitStruct.Pull = GPIO_PULLUP;

  // PA13: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PA13: Alternate Function 0 (SWD & JTAG)
  GPIO_InitStruct.Alternate = GPIO_AF0_SWJ;

  // PA13: Since the convention in this file is to use pin numbers,
  // We will use GPIO_PIN_13 and not SWDIO_PIN
  GPIO_InitStruct.Pin = GPIO_PIN_13;

  // Apply the Configuration to PA14
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // PA14: Alternate Function Push Pull
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;

  // PA14: Pull Down (SWCLK)
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;

  // PA14: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PA14: Alternate Function 0 (SWD & JTAG)
  GPIO_InitStruct.Alternate = GPIO_AF0_SWJ;

  // PA14: Since the convention in this file is to use pin numbers,
  // We will use GPIO_PIN_14 and not SWCLK_PIN
  GPIO_InitStruct.Pin = GPIO_PIN_14;

  // Apply the Configuration to PA14
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/*********************************** GPIO B ***********************************/

  // GPIOB Setup : All pins will be initialized to floating inputs
  // GPIOB RCC Clock should be enabled
  __HAL_RCC_GPIOB_CLK_ENABLE();

  // PB0-PB15: Floating Input
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  // PB0-PB15: No Pull Up / Pull Down
  GPIO_InitStruct.Pull = GPIO_NOPULL;

  // PB0-PB15: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PB0-PB15: Use GPIO_PIN_All
  GPIO_InitStruct.Pin = GPIO_PIN_All;

  // Apply the Configuration to GPIOB
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/*********************************** GPIO C ***********************************/

  // GPIOC Setup : All pins will be initialized to floating inputs
  // GPIOC RCC Clock should be enabled
  __HAL_RCC_GPIOC_CLK_ENABLE();

  // PC0-PC15: Floating Input
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  // PC0-PC15: No Pull Up / Pull Down
  GPIO_InitStruct.Pull = GPIO_NOPULL;

  // PC0-PC15: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PC0-PC15: Use GPIO_PIN_All
  GPIO_InitStruct.Pin = GPIO_PIN_All;

  // Apply the Configuration to GPIOC
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/*********************************** GPIO D ***********************************/

  // GPIOD Setup : All pins will be initialized to floating inputs
  // GPIOD RCC Clock should be enabled
  __HAL_RCC_GPIOD_CLK_ENABLE();

  // PD0-PD15: Floating Input
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  // PD0-PD15: No Pull Up / Pull Down
  GPIO_InitStruct.Pull = GPIO_NOPULL;

  // PD0-PD15: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PD0-PD15: Use GPIO_PIN_All
  GPIO_InitStruct.Pin = GPIO_PIN_All;

  // Apply the Configuration to GPIOD
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/*********************************** GPIO E ***********************************/

  // GPIOE Setup : All pins will be initialized to floating inputs
  // GPIOE RCC Clock should be enabled
  __HAL_RCC_GPIOE_CLK_ENABLE();

  // PE0-PE15: Floating Input
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  // PE0-PE15: No Pull Up / Pull Down
  GPIO_InitStruct.Pull = GPIO_NOPULL;

  // PE0-PE15: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PE0-PE15: Use GPIO_PIN_All
  GPIO_InitStruct.Pin = GPIO_PIN_All;

  // Apply the Configuration to GPIOE
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

/*********************************** GPIO H ***********************************/

  // GPIOH Setup : All pins will be initialized to floating inputs
  // GPIOH RCC Clock should be enabled
  __HAL_RCC_GPIOH_CLK_ENABLE();

  // PH0, PH1: Floating Input
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  // PH0, PH1: No Pull Up / Pull Down
  GPIO_InitStruct.Pull = GPIO_NOPULL;

  // PH0, PH1: Highest Speed
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // PH0, PH1: Pin 0 & Pin 1 (Apply OR between masks)
  GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;

  // Apply the Configuration to GPIOH
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

}
