#include "switches.h"
#include "board.h"
#include "stm32f7xx_hal.h"

static int current_range;

void Switches_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct;

  // All switches will be configured as OUTPUT_PUSHPULL
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

  GPIO_InitStruct.Pin = uP_SW1_PIN;
  HAL_GPIO_Init(uP_SW1_GPIO, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = uP_SW2_PIN;
  HAL_GPIO_Init(uP_SW2_GPIO, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = MIRROR_RESISTOR_PIN;
  HAL_GPIO_Init(MIRROR_RESISTOR_GPIO, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = USE_MODE_PIN;
  HAL_GPIO_Init(USE_MODE_GPIO, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = CALIB_CTRL_P_PIN;
  HAL_GPIO_Init(CALIB_CTRL_P_GPIO, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = CALIB_CTRL_N_PIN;
  HAL_GPIO_Init(CALIB_CTRL_N_GPIO, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = DUT_CTRL_P_PIN;
  HAL_GPIO_Init(DUT_CTRL_P_GPIO, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = CALIB_CTRL_N_PIN;
  HAL_GPIO_Init(DUT_CTRL_N_GPIO, &GPIO_InitStruct);

  // Initial State : Use uP
  Set_Use_Mode_uP();

  // Initial State : Both Calib & DUT are disconnected
  Disconnect_Shunt();

  // Initial State : Both SW1 and SW2 are closed (MA Range)
  Switch_To_Range(MA_RANGE);
  current_range = MA_RANGE;

  // Initial State : 5M resistor is connected
  Use_5M_Mirror();
}

void Set_Use_Mode_FPGA(void) {
  HAL_GPIO_WritePin(USE_MODE_GPIO, USE_MODE_PIN, GPIO_PIN_RESET);
}

void Set_Use_Mode_uP(void) {
  HAL_GPIO_WritePin(USE_MODE_GPIO, USE_MODE_PIN, GPIO_PIN_SET);
}

void Close_Calib_Ctrl_N(void) {
  HAL_GPIO_WritePin(CALIB_CTRL_N_GPIO, CALIB_CTRL_N_PIN, GPIO_PIN_RESET);
}

void Open_Calib_Ctrl_N(void) {
  HAL_GPIO_WritePin(CALIB_CTRL_N_GPIO, CALIB_CTRL_N_PIN, GPIO_PIN_SET);
}

void Close_Calib_Ctrl_P(void) {
  HAL_GPIO_WritePin(CALIB_CTRL_P_GPIO, CALIB_CTRL_P_PIN, GPIO_PIN_RESET);
}

void Open_Calib_Ctrl_P(void) {
  HAL_GPIO_WritePin(CALIB_CTRL_P_GPIO, CALIB_CTRL_P_PIN, GPIO_PIN_SET);
}

void Close_DUT_Ctrl_N(void) {
  HAL_GPIO_WritePin(DUT_CTRL_N_GPIO, DUT_CTRL_N_PIN, GPIO_PIN_RESET);
}

void Open_DUT_Ctrl_N(void) {
  HAL_GPIO_WritePin(DUT_CTRL_N_GPIO, DUT_CTRL_N_PIN, GPIO_PIN_SET);
}

void Close_DUT_Ctrl_P(void) {
  HAL_GPIO_WritePin(DUT_CTRL_P_GPIO, DUT_CTRL_P_PIN, GPIO_PIN_RESET);
}

void Open_DUT_Ctrl_P(void) {
  HAL_GPIO_WritePin(DUT_CTRL_P_GPIO, DUT_CTRL_P_PIN, GPIO_PIN_SET);
}

void Connect_Shunt_Calib(void) {
  Open_DUT_Ctrl_P();
  Open_DUT_Ctrl_N();
  Close_Calib_Ctrl_P();
  Close_Calib_Ctrl_N();
}

void Connect_Shunt_DUT(void) {
  Open_Calib_Ctrl_P();
  Open_Calib_Ctrl_N();
  Close_DUT_Ctrl_P();
  Close_DUT_Ctrl_N();
}

void Disconnect_Shunt(void) {
  Open_DUT_Ctrl_P();
  Open_DUT_Ctrl_N();
  Open_Calib_Ctrl_P();
  Open_Calib_Ctrl_N();
}

void Use_1K_Mirror(void) {
  HAL_GPIO_WritePin(MIRROR_RESISTOR_GPIO, MIRROR_RESISTOR_PIN, GPIO_PIN_SET);
}

void Use_5M_Mirror(void) {
  HAL_GPIO_WritePin(MIRROR_RESISTOR_GPIO, MIRROR_RESISTOR_PIN, GPIO_PIN_RESET);
}

void Switch_To_Range(int range) {
  current_range = range;

  switch (range) {
  case MA_RANGE:
    HAL_GPIO_WritePin(uP_SW1_GPIO, uP_SW1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(uP_SW2_GPIO, uP_SW2_PIN, GPIO_PIN_RESET);
    break;

  case UA_RANGE:
    HAL_GPIO_WritePin(uP_SW1_GPIO, uP_SW1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(uP_SW2_GPIO, uP_SW2_PIN, GPIO_PIN_RESET);
    break;

  case NA_RANGE:
    HAL_GPIO_WritePin(uP_SW1_GPIO, uP_SW1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(uP_SW2_GPIO, uP_SW2_PIN, GPIO_PIN_SET);
    break;
  }
}

int Get_Current_Range(void) {
    return current_range;
}
