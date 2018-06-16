#include "dac.h"
#include "board.h"
#include "stm32f7xx_hal.h"

// DAC Driver
DAC_HandleTypeDef DAC_Struct;

void DAC_Init(void) {
  // Enable DAC Clock
  __HAL_RCC_DAC_CLK_ENABLE();

  DAC_Struct.Instance = DAC;
  if(HAL_DAC_Init(&DAC_Struct) != HAL_OK) {
    _Error_Handler(__FILE__, __LINE__);
  }

  // Configure Ref_On and Ref_Off as Analog inputs (Manual)
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Pin  = DAC_VREF_ON_PIN;
  HAL_GPIO_Init(DAC_VREF_ON_GPIO, &GPIO_InitStruct);
  GPIO_InitStruct.Pin  = DAC_VREF_OFF_PIN;
  HAL_GPIO_Init(DAC_VREF_OFF_GPIO, &GPIO_InitStruct);

  // DAC Channel Configuration
  DAC_ChannelConfTypeDef Channel_Config_Struct;

  Channel_Config_Struct.DAC_Trigger = DAC_TRIGGER_NONE;
  Channel_Config_Struct.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;

  HAL_DAC_ConfigChannel(&DAC_Struct, &Channel_Config_Struct, DAC_CHANNEL_1);
  HAL_DAC_ConfigChannel(&DAC_Struct, &Channel_Config_Struct, DAC_CHANNEL_2);

  // Start the drivers
  HAL_DAC_Start(&DAC_Struct, DAC_CHANNEL_1);
  HAL_DAC_Start(&DAC_Struct, DAC_CHANNEL_2);
}

void DAC_Set_Ref_On(uint16_t output) {
  HAL_DAC_SetValue(&DAC_Struct, DAC_CHANNEL_1, DAC_ALIGN_12B_R, output);
}

void DAC_Set_Ref_Off(uint16_t output) {
  HAL_DAC_SetValue(&DAC_Struct, DAC_CHANNEL_2, DAC_ALIGN_12B_R, output);
}
