#ifndef BOARD_H
#define BOARD_H

/******************************* IO Assignments *******************************/

/*********************************** GPIO A ***********************************/

// DUT_CTRL_N (A0): Switch that connecting DUT's low side to the circuit.
#define DUT_CTRL_N_GPIO                  GPIOA
#define DUT_CTRL_N_PIN                   0U

// ETH_REF_CLK (A1): Ethernet Reference Clock.
#define ETH_REF_CLK_GPIO                 GPIOA
#define ETH_REF_CLK_PIN                  1U

// ETH_MDIO (A2): Ethernet Management Data Input Output.
#define ETH_MDIO_GPIO                    GPIOA
#define ETH_MDIO_PIN                     2U

// BAT_SENSE (A3): Battery Sense (Internal ADC); Detect low battery level.
#define BAT_SENSE_GPIO                   GPIOA
#define BAT_SENSE_PIN                    3U

// VREF_ON (A4): DAC Output to specify Higher Reference Voltage (Calibration).
#define DAC_VREF_ON_GPIO                 GPIOA
#define DAC_VREF_ON_PIN                  4U

// VREF_OFF (A5): DAC Output to specify Lower Reference Voltage (Calibration).
#define DAC_VREF_OFF_GPIO                GPIOA
#define DAC_VREF_OFF_PIN                 5U

// Unused pin (A6)
#define UNUSED_A_1_GPIO                  GPIOA
#define UNUSED_A_1_PIN                   6U

// ETH_CRS_DV (A7): Ethernet Carrier Sense / Receive Data Valid.
#define ETH_CRS_DV_GPIO                  GPIOA
#define ETH_CRS_DV_PIN                   7U

// CONTEXT_4 (A8): DUT's Context GPIO #4 (Input).
#define CONTEXT_4_GPIO                   GPIOA
#define CONTEXT_4_PIN                    8U

// USB_VBUS (A9): USB Voltage Supply.
#define USB_VBUS_GPIO                    GPIOA
#define USB_VBUS_PIN                     9U

// CONTEXT_3 (A10): DUT's Context GPIO #3 (Input).
#define CONTEXT_3_GPIO                   GPIOA
#define CONTEXT_3_PIN                    10U

// USB_DM (A11): USB Data-.
#define USB_DM_GPIO                      GPIOA
#define USB_DM_PIN                       11U

// USB_DP (A12): USB Data+.
#define USB_DP_GPIO                      GPIOA
#define USB_DP_PIN                       12U

// SWDIO (A13): Serial Wire Data Input Output (JTAG/SWD Connector).
#define SWDIO_GPIO                       GPIOA
#define SWDIO_PIN                        13U

// SWCLK (A14): Serial Wire Clock (JTAG/SWD Connector).
#define SWCLK_GPIO                       GPIOA
#define SWCLK_PIN                        14U

// uP_MCLK (A15): External ADC Master Clock (Transferred to ADC through FPGA).
#define uP_MCLK_GPIO                     GPIOA
#define uP_MCLK_PIN                      15U

/*********************************** GPIO B ***********************************/

// Unused pin (B0)
#define UNUSED_B_1_GPIO                  GPIOB
#define UNUSED_B_1_PIN                   0U

// Unused pin (B1)
#define UNUSED_B_2_GPIO                  GPIOB
#define UNUSED_B_2_PIN                   1U

// Boot (B2).
#define BOOT1_GPIO                       GPIOB
#define BOOT1_PIN                        2U

// SPI_FPGA_SCLK (B3): FPGA's SPI Slave Clock
#define SPI_FPGA_SCLK_GPIO               GPIOB
#define SPI_FPGA_SCLK_PIN                3U

// SPI_FPGA_MISO (B4): FPGA's SPI Slave --> Master.
#define SPI_FPGA_MISO_GPIO               GPIOB
#define SPI_FPGA_MISO_PIN                4U

// SPI_FPGA_MOSI (B5): FPGA's SPI Master --> Slave.
#define SPI_FPGA_MOSI_GPIO               GPIOB
#define SPI_FPGA_MOSI_PIN                5U

// ALERT (B6): Comparator's output: Burden voltage exceeded the accepted value
// --> Switch to mA Range.
#define ALERT_GPIO                       GPIOB
#define ALERT_PIN                        6U

// uP_SW1 (B7): Control the SW2 connected to R=0.07 (Transferred through FPGA).
#define uP_SW1_GPIO                      GPIOB
#define uP_SW1_PIN                       7U

// SPI_FPGA_CSn (B8): FPGA's SPI Chip Select.
#define SPI_FPGA_CSn_GPIO                GPIOB
#define SPI_FPGA_CSn_PIN                 8U

// VIN_LESS_VOFF (B9): Output of the Comparator Vin < Vref_off.
#define VIN_LESS_VOFF_GPIO               GPIOB
#define VIN_LESS_VOFF_PIN                9U

// Unused pin (B10)
#define UNUSED_B_3_GPIO                  GPIOB
#define UNUSED_B_3_PIN                   10U

// ETH_TX_EN (B11): Ethernet Transfer Enable.
#define ETH_TX_EN_GPIO                   GPIOB
#define ETH_TX_EN_PIN                    11U

// ETH_TX_D0 (B12): Ethernet Transfer D0.
#define ETH_TX_D0_GPIO                   GPIOB
#define ETH_TX_D0_PIN                    12U

// ETH_TX_D1 (B13): Ethernet Transfer D1.
#define ETH_TX_D1_GPIO                   GPIOB
#define ETH_TX_D1_PIN                    13U

// Unused pin (B14)
#define UNUSED_B_4_GPIO                  GPIOB
#define UNUSED_B_4_PIN                   14U

// Unused pin (B15)
#define UNUSED_B_5_GPIO                  GPIOB
#define UNUSED_B_5_PIN                   15U

/*********************************** GPIO C ***********************************/

// CALIB_CTRL_N (C0): Switch connecting Mirror's low side to the circuit.
#define CALIB_CTRL_N_GPIO                GPIOC
#define CALIB_CTRL_N_PIN                 0U

// ETH_MDC (C1): Ethernet Management Data Clock.
#define ETH_MDC_GPIO                     GPIOC
#define ETH_MDC_PIN                      1U

// CALIB_CTRL_P (C2): Switch connecting Mirror's high side to the circuit.
#define CALIB_CTRL_P_GPIO                GPIOC
#define CALIB_CTRL_P_PIN                 2U

// DUT_CTRL_P (C3): Switch connecting DUT's high side to the circuit.
#define DUT_CTRL_P_GPIO                  GPIOC
#define DUT_CTRL_P_PIN                   3U

// ETH_RX_D0 (C4): Ethernet Receive D0.
#define ETH_RX_D0_GPIO                   GPIOC
#define ETH_RX_D0_PIN                    4U

// ETH_RX_D1 (C5): Ethernet Receive D1.
#define ETH_RX_D1_GPIO                   GPIOC
#define ETH_RX_D1_PIN                    5U

// Unused pin (C6)
#define UNUSED_C_1_GPIO                  GPIOC
#define UNUSED_C_1_PIN                   6U

// CONTEXT_5 (C7): DUT's Context GPIO #5 (Input).
#define CONTEXT_5_GPIO                   GPIOC
#define CONTEXT_5_PIN                    7U

// SD_D0 (C8): SD Card Data 0.
#define SD_D0_GPIO                       GPIOC
#define SD_D0_PIN                        8U

// SD_D1 (C9): SD Card Data 1.
#define SD_D1_GPIO                       GPIOC
#define SD_D1_PIN                        9U

// SD_D2 (C10): SD Card Data 2.
#define SD_D2_GPIO                       GPIOC
#define SD_D2_PIN                        10U

// SD_D3 (C11): SD Card Data 3.
#define SD_D3_GPIO                       GPIOC
#define SD_D3_PIN                        11U

// SD_CLK (C12): SD Card Clock.
#define SD_CLK_GPIO                      GPIOC
#define SD_CLK_PIN                       12U

// MIRROR_RESISTOR (C13): Chose the resistor (5M / 1K) connected to the mirror.
#define MIRROR_RESISTOR_GPIO             GPIOC
#define MIRROR_RESISTOR_PIN              13U

// FPGA_CLEAR (C14): FPGA Clear Signal.
#define FPGA_CLEAR_GPIO                  GPIOC
#define FPGA_CLEAR_PIN                   14U

// Unused Pin (C15)
#define UNUSED_C_2_GPIO                  GPIOC
#define UNUSED_C_2_PIN                   15U

/*********************************** GPIO D ***********************************/

// CONTEXT_1 (D0): DUT's Context GPIO #1 (Input).
#define CONTEXT_1_GPIO                   GPIOD
#define CONTEXT_1_PIN                    0U

// CONTEXT_2 (D1): DUT's Context GPIO #2 (Input).
#define CONTEXT_2_GPIO                   GPIOD
#define CONTEXT_2_PIN                    1U

// SD_CMD (D2): SD Card Command.
#define SD_CMD_GPIO                      GPIOD
#define SD_CMD_PIN                       2U

// FPGA_OE (D3): FPGA Output Enable.
#define FPGA_OE1_GPIO                    GPIOD
#define FPGA_OE1_PIN                     3U

// uP_DRDY (D4): External ADC Data Ready Signal (Transferred to uC through FPGA).
#define uP_DRDY_GPIO                     GPIOD
#define uP_DRDY_PIN                      4U

// uP_SW2 (D5): Control the SW2 connected to R=10 (Transferred through FPGA).
#define uP_SW2_GPIO                      GPIOD
#define uP_SW2_PIN                       5U

// USE_MODE (D6): Specify if FPGA is transparent or active.
#define USE_MODE_GPIO                    GPIOD
#define USE_MODE_PIN                     6U

// uP_PDn (D7): External ADC Power Down (Transferred to ADC through FPGA).
#define uP_PDn_GPIO                      GPIOD
#define uP_PDn_PIN                       7U

// SW_START_STOP_ACQUISITION (D8): Generic IO.
// Should be connected to an external Start / Stop Switch.
#define SW_START_STOP_ACQUISITION_GPIO   GPIOD
#define SW_START_STOP_ACQUISITION_PIN    8U

// SW_STANDALONE_STREAMING (D9): Generic IO
// Should be conencted to an external Standalone / Streaming selection Switch.
#define SW_STANDALONE_STREAMING_GPIO     GPIOD
#define SW_STANDALONE_STREAMING_PIN      9U

// LED_START_STOP_ACQUISITION (D10): Generic IO
// Should be connected to a LED indicating acquisition status.
#define LED_START_STOP_ACQUISITION_GPIO  GPIOD
#define LED_START_STOP_ACQUISITION_PIN   10U

// LED_AMPEROSE_ON_OFF (D11): Generic IO
// Should be connected to a LED indicating Amperose's status.
#define LED_AMPEROSE_ON_OFF_GPIO         GPIOD
#define LED_AMPEROSE_ON_OFF_PIN          11U

// Unused Pin (D12)
#define UNUSED_D_1_GPIO                  GPIOD
#define UNUSED_D_1_PIN                   12U

// RGB_R (D13): RGB Led Red Pin.
#define RGB_R_GPIO                       GPIOD
#define RGB_R_PIN                        13U

// RGB_G (D14): RGB Led Green Pin.
#define RGB_G_GPIO                       GPIOD
#define RGB_G_PIN                        14U

// RGB_B (D15): RGB Led Blue Pin.
#define RGB_B_GPIO                       GPIOD
#define RGB_B_PIN                        15U

/*********************************** GPIO E ***********************************/

// FPGA_CLK (E0): Clock of the FPGA (Output of SAI).
#define FPGA_CLK_GPIO                    GPIOE
#define FPGA_CLK_PIN                     0U

// VIN_GREATER_VON (E1): Output of the Comparator Vin > Vref_on.
#define VIN_GREATER_VON_GPIO             GPIOE
#define VIN_GREATER_VON_PIN              1U

// SPI_POT_SCLK (E2): Potentiometer's SPI Slave Clock.
#define SPI_POT_SCLK_GPIO                GPIOE
#define SPI_POT_SCLK_PIN                 2U

// SPI_POT_BURDEN_CSn (E3): Burden Voltage Potentiometer's Chip Select.
#define SPI_POT_BURDEN_CSn_GPIO          GPIOE
#define SPI_POT_BURDEN_CSn_PIN           3U

// SPI_POT_MIRROR_CSn (E4): Current Mirror Potentiometer's Chip Select.
#define SPI_POT_MIRROR_CSn_GPIO          GPIOE
#define SPI_POT_MIRROR_CSn_PIN           4U

// SPI_POT_MISO (E5): Potentiometer's SPI Slave --> Master.
#define SPI_POT_MISO_GPIO                GPIOE
#define SPI_POT_MISO_PIN                 5U

// SPI_POT_MOSI (E6): Potentiometer's SPI Master --> Slave.
#define SPI_POT_MOSI_GPIO                GPIOE
#define SPI_POT_MOSI_PIN                 6U

// Unused pin (E7)
#define UNUSED_E_1_GPIO                  GPIOE
#define UNUSED_E_1_PIN                   7U

// Unused pin (E8)
#define UNUSED_E_2_GPIO                  GPIOE
#define UNUSED_E_2_PIN                   8U

// Unused pin (E9)
#define UNUSED_E_3_GPIO                  GPIOE
#define UNUSED_E_3_PIN                   9U

// Unused pin (E10)
#define UNUSED_E_4_GPIO                  GPIOE
#define UNUSED_E_4_PIN                   10U

// PHY_RSTn (E11): Reset the Ethernet Physical Transceiver PHY.
#define PHY_RSTn_GPIO                    GPIOE
#define PHY_RSTn_PIN                     11U

// Unused pin (E12)
#define UNUSED_E_5_GPIO                  GPIOE
#define UNUSED_E_5_PIN                   12U

// Unused pin (E13)
#define UNUSED_E_6_GPIO                  GPIOE
#define UNUSED_E_6_PIN                   13U

// Unused pin (E14)
#define UNUSED_E_7_GPIO                  GPIOE
#define UNUSED_E_7_PIN                   14U

// Unused pin (E15)
#define UNUSED_E_8_GPIO                  GPIOE
#define UNUSED_E_8_PIN                   15U

/*********************************** GPIO H ***********************************/

// OSC_IN (H0): Oscillator Input.
#define OSC_IN_GPIO                      GPIOH
#define OSC_IN_PIN                       0U

// OSC_OUT (H1): Oscillator Output.
#define OSC_OUT_GPIO                     GPIOH
#define OSC_OUT_PIN                      1U

#endif
