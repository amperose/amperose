#ifndef SWITCHES_H
#define SWITCHES_H

#define MA_RANGE 3
#define UA_RANGE 2
#define NA_RANGE 1

void Switches_Init(void);

void Set_Use_Mode_FPGA(void);
void Set_Use_Mode_uP  (void);

void Close_Calib_Ctrl_P(void);
void Open_Calib_Ctrl_P (void);

void Close_Calib_Ctrl_N(void);
void Open_Calib_Ctrl_N (void);

void Close_DUT_Ctrl_P(void);
void Open_DUT_Ctrl_P (void);

void Close_DUT_Ctrl_N(void);
void Open_DUT_Ctrl_N (void);

void Connect_Shunt_Calib(void);
void Connect_Shunt_DUT  (void);
void Disconnect_Shunt   (void);

void Use_1K_Mirror(void);
void Use_5M_Mirror(void);

void Switch_To_Range  (int range);
int  Get_Current_Range(void);

#endif
