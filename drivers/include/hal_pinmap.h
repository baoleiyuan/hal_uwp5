/*
 * Copyright (c) 2018, UNISOC Incorporated
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef HAL_PINMAP_H
#define HAL_PINMAP_H

/**************************************************
 * Included Files
 *****************************************************/

#include "uwp_hal.h"
#include <device.h>


/*********************************************************
 * Pre-processor Definitions
 ********************************************************/

/*
 *pinmap ctrl register Bit field value
 *|Reserved[31:16] | Drv btr sel[15:14] | bsr wpus[12] | bsr se[11]
 *| func PU[8] | func PD[7] |func sel[6:4] | PU[3] | PD[2]
 *| input En[1] | output En[0] |
 */
#define PIN_Z_EN           0x00
#define PIN_O_EN           BIT(0)
#define PIN_I_EN           BIT(1)

#define PIN_SPD_EN         BIT(2)
#define PIN_SPU_EN         BIT(3)
#define PIN_SPX_EN         0x00

#define PIN_FUNC_DEF       (0X00<<4)
#define PIN_FUNC_1         (0X01<<4)
#define PIN_FUNC_2         (0X02<<4)
#define PIN_FUNC_3         (0X03<<4)
#define PIN_FUNC_4         (0X04<<4)
#define PIN_FUNC_5         (0X05<<4)

#if defined(CONFIG_SOC_UWP5661)
#define PIN_FUNC_MSK       (0X07<<4)
#define PIN_FPD_EN         BIT(7)
#define PIN_FPU_EN         BIT(8)
#define PIN_FPX_EN         0X00
#define PIN_FPU_MSK        (0X03<<7)
#define PIN_DS_0           (0x00<<14)
#define PIN_DS_1           (0x01<<14)
#define PIN_DS_2           (0x02<<14)
#define PIN_DS_3           (0x03<<14)
#define PIN_DS_4           (0x04<<14)
#define PIN_DS_5           (0x05<<14)
#define PIN_DS_6           (0x06<<14)
#define PIN_DS_7           (0x07<<14)
#elif defined(CONFIG_SOC_UWP5662)
#define PIN_FUNC_MSK       (0X03<<4)
#define PIN_FPD_EN         BIT(6)
#define PIN_FPU_EN         BIT(7)
#define PIN_FPX_EN         0x00
#define PIN_FPU_MSK        (0x03<<6)
#define PIN_PADI_SWITCH    (0x01<<10)
#define PIN_DSLP_MSK       (0x03<<13)
#define PIN_DS_0           (0x00<<19)
#define PIN_DS_1           (0x01<<19)
#define PIN_DS_2           (0x02<<19)
#define PIN_DS_3           (0x03<<19)
#define PIN_DS_4           (0x04<<19)
#define PIN_DS_5           (0x05<<19)
#define PIN_DS_6           (0x06<<19)
#define PIN_DS_7           (0x07<<19)
#endif

#define PIN_SE_EN          BIT(11)
#define PIN_SE_DEF         0x0000

#define PIN_WPUS_EN        BIT(12)
#define PIN_WPUS_DEF       0x0000

#define    PIN_XTLEN_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_IISDO_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_IISCLK_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_IISLRCK_VALUE       (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_IISDI_VALUE         (PIN_DS_1 | PIN_FPD_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_PTEST_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPD_EN | PIN_WPUS_DEF | PIN_I_EN)

#define    PIN_GPIO0_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_GPIO1_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_GPIO2_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)

#define    PIN_RST_N_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_WCI_2_RXD_VALUE     (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_WCI_2_TXD_VALUE     (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_INT_VALUE           (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_MTMS_VALUE          (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPD_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_MTCK_VALUE          (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPD_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_U0TXD_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_U0RXD_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_U0RTS_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_U0CTS_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)

/* add new pin */
#define    PIN_GPIO3_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_ESMD3_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPD_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_ESMD1_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPD_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_ESMD0_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPD_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_ESMCSN_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_ESMSMP_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_ESMCLK_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_U3TXD_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_U3RXD_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_I_EN)

#define    PIN_RFCTL0_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_RFCTL1_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_RFCTL2_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_RFCTL3_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_RFCTL4_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_RFCTL5_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_RFCTL6_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_RFCTL7_VALUE        (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_GNSS_LNA_EN_VALUE   (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_U1TXD_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_U1RXD_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_U1RTS_VALUE         (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define    PIN_U1CTS_VALUE         (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_PCIE_CLKREQ_L_VALUE (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_PCIE_RST_L_VALUE    (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)
#define    PIN_PCIE_WAKE_L_VALUE   (PIN_DS_1 | PIN_FPX_EN | \
PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN)
#define    PIN_CHIP_EN_VALUE       (PIN_DS_1 | PIN_FPU_EN | \
PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)

#if defined(CONFIG_SOC_UWP5662)
#define PIN_SD_D3_VALUE		(PIN_DS_5 | PIN_FPX_EN \
| PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_D2_VALUE		(PIN_DS_5 | PIN_FPX_EN \
| PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_D1_VALUE		(PIN_DS_5 | PIN_FPX_EN \
| PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_D0_VALUE		(PIN_DS_5 | PIN_FPX_EN \
| PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_CMD_VALUE	(PIN_DS_5 | PIN_FPX_EN \
| PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_CLK_VALUE	(PIN_DS_5 | PIN_FPX_EN \
| PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#elif defined(CONFIG_SOC_UWP5661)
#define PIN_SD_D3_VALUE		(PIN_DS_2 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_D2_VALUE		(PIN_DS_2 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_D1_VALUE		(PIN_DS_2 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_D0_VALUE		(PIN_DS_2 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_CMD_VALUE	(PIN_DS_2 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_SD_CLK_VALUE	(PIN_DS_2 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN)
#endif
/*add new pin*/

#if defined(CONFIG_SOC_UWP5662)
#define PIN_ESMD2_VALUE		(PIN_DS_1 | PIN_FPU_EN \
| PIN_SPD_EN | PIN_WPUS_DEF | PIN_I_EN)
#elif defined(CONFIG_SOC_UWP5661)
#define PIN_ESMD2_VALUE		(PIN_DS_1 | PIN_FPU_EN \
| PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)
#endif

#define PIN_U2TXD_VALUE		(PIN_DS_1 | PIN_FPX_EN \
| PIN_SPU_EN | PIN_WPUS_DEF | PIN_Z_EN)
#define PIN_U2RXD_VALUE		(PIN_DS_1 | PIN_FPU_EN \
| PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN)

/*******************redefined pinmap ***************************/

#define     GPIO_USART1_TX_2        PIN_U0TXD_VALUE
#define     GPIO_USART1_RX_2        PIN_U0RXD_VALUE
#define     GPIO_USART1_RTS_DE_2    PIN_U0RTS_VALUE
#define     GPIO_USART1_CTS_3       PIN_U0CTS_VALUE

#define     GPIO_USART2_TX_1        PIN_U1TXD_VALUE
#define     GPIO_USART2_RX_1        PIN_U1RXD_VALUE
#define     GPIO_USART2_RTS_DE_1    PIN_U1RTS_VALUE
#define     GPIO_USART2_CTS_1       PIN_U1CTS_VALUE

#define     GPIO_USART3_RX_3        PIN_U3TXD_VALUE
#define     GPIO_USART3_TX_3        PIN_U3RXD_VALUE

#define     GPIO_USART_TX	((PIN_DS_1 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_O_EN))
#define     GPIO_USART_RX	((PIN_DS_1 | PIN_FPU_EN \
| PIN_FUNC_DEF | PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN))
#define     GPIO_USART_RTS_DE	((PIN_DS_1 | PIN_FPX_EN \
| PIN_FUNC_DEF | PIN_SPX_EN | PIN_WPUS_DEF | PIN_Z_EN))
#define     GPIO_USART_CTS	((PIN_DS_1 | PIN_FPU_EN \
| PIN_FUNC_DEF | PIN_SPU_EN | PIN_WPUS_DEF | PIN_I_EN))

#endif /* __ARCH_ARM_SRC_SPRD_CHIP_SC2355A_PINMAP_H */
