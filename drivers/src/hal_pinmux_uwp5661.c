/*
 * Copyright (c) 2018, UNISOC Incorporated
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "uwp_hal.h"
#ifdef __cpluscplus
extern "C"
{
#endif

#define PM_INVALID_VAL 0xffffffff
#define PM_INVALID_SHORT_VAL 0xffff


static struct pm_pinfunc_tag pm_func[] = {
	/*| pin register*/
	{PIN_PIN_CRTL_REG0, 0x00000000},
	{PIN_PIN_CRTL_REG1, 0x00000000},
	{PIN_PIN_CRTL_REG2, 0x00000000},
	{PIN_PIN_CRTL_REG3, 0x00000000},

	{PIN_XTLEN_REG,       PIN_XTLEN_VALUE | PIN_FUNC_DEF },
	{PIN_IISDO_REG,       PIN_IISDO_VALUE | PIN_FUNC_DEF },
	{PIN_IISCLK_REG,      PIN_IISCLK_VALUE | PIN_FUNC_DEF },
	{PIN_IISLRCK_REG,     PIN_IISLRCK_VALUE | PIN_FUNC_DEF },
	{PIN_IISDI_REG,       PIN_IISDI_VALUE | PIN_FUNC_DEF },
	{PIN_PTEST_REG,       PIN_PTEST_VALUE | PIN_FUNC_DEF },

	{PIN_GPIO0_REG,       PIN_GPIO0_VALUE | PIN_FUNC_DEF },
	{PIN_GPIO1_REG,       PIN_GPIO1_VALUE | PIN_FUNC_DEF },
	{PIN_GPIO2_REG,       PIN_GPIO2_VALUE | PIN_FUNC_DEF },

	{PIN_RST_N_REG,       PIN_RST_N_VALUE | PIN_FUNC_DEF },
	{PIN_WCI_2_RXD_REG,   PIN_WCI_2_RXD_VALUE | PIN_FUNC_DEF },
	{PIN_WCI_2_TXD_REG,   PIN_WCI_2_TXD_VALUE | PIN_FUNC_DEF },
	{PIN_INT_REG,         PIN_INT_VALUE | PIN_FUNC_DEF },
	{PIN_MTMS_REG,        PIN_MTMS_VALUE | PIN_FUNC_DEF },
	{PIN_MTCK_REG,        PIN_MTCK_VALUE | PIN_FUNC_DEF },
	{PIN_U0TXD_REG,       PIN_U0TXD_VALUE | PIN_FUNC_DEF },
	{PIN_U0RXD_REG,       PIN_U0RXD_VALUE | PIN_FUNC_DEF },
	{PIN_U0RTS_REG,       PIN_U0RTS_VALUE | PIN_FUNC_DEF },
	{PIN_U0CTS_REG,       PIN_U0CTS_VALUE | PIN_FUNC_DEF },

	{PIN_SD_D3_REG,        PIN_SD_D3_VALUE | PIN_FUNC_DEF },
	{PIN_SD_D2_REG,        PIN_SD_D2_VALUE | PIN_FUNC_DEF },
	{PIN_SD_D1_REG,        PIN_SD_D1_VALUE | PIN_FUNC_DEF },
	{PIN_SD_D0_REG,        PIN_SD_D0_VALUE | PIN_FUNC_DEF },
	{PIN_SD_CMD_REG,       PIN_SD_CMD_VALUE | PIN_FUNC_DEF },
	{PIN_SD_CLK_REG,       PIN_SD_CLK_VALUE | PIN_FUNC_DEF },

	{PIN_GPIO3_REG,         PIN_GPIO3_VALUE | PIN_FUNC_DEF },
	{PIN_ESMD3_REG,         PIN_ESMD3_VALUE | PIN_FUNC_DEF },
	{PIN_ESMD2_REG,         PIN_ESMD2_VALUE | PIN_FUNC_DEF },
	{PIN_ESMD1_REG,         PIN_ESMD1_VALUE | PIN_FUNC_DEF },
	{PIN_ESMD0_REG,         PIN_ESMD0_VALUE | PIN_FUNC_DEF },
	{PIN_ESMCSN_REG,        PIN_ESMCSN_VALUE | PIN_FUNC_DEF },
	{PIN_ESMSMP_REG,        PIN_ESMSMP_VALUE | PIN_FUNC_DEF },
	{PIN_ESMCLK_REG,        PIN_ESMCLK_VALUE | PIN_FUNC_DEF },
	{PIN_U3TXD_REG,         PIN_U3TXD_VALUE | PIN_FUNC_DEF },
	{PIN_U3RXD_REG,         PIN_U3RXD_VALUE | PIN_FUNC_DEF },

	{PIN_RFCTL0_REG,        PIN_RFCTL0_VALUE | PIN_FUNC_DEF },
	{PIN_RFCTL1_REG,        PIN_RFCTL1_VALUE | PIN_FUNC_DEF },
	{PIN_RFCTL2_REG,        PIN_RFCTL2_VALUE | PIN_FUNC_DEF },
	{PIN_RFCTL3_REG,        PIN_RFCTL3_VALUE | PIN_FUNC_DEF },
	{PIN_RFCTL4_REG,        PIN_RFCTL4_VALUE | PIN_FUNC_DEF },
	{PIN_RFCTL5_REG,        PIN_RFCTL5_VALUE | PIN_FUNC_3 },
	{PIN_RFCTL6_REG,        PIN_RFCTL6_VALUE | PIN_FUNC_3 },
	{PIN_RFCTL7_REG,        PIN_RFCTL7_VALUE | PIN_FUNC_3 },

	{PIN_GNSS_LNA_EN_REG,    PIN_GNSS_LNA_EN_VALUE | PIN_FUNC_DEF },
	{PIN_U1TXD_REG,          PIN_U1TXD_VALUE | PIN_FUNC_DEF },
	{PIN_U1RXD_REG,          PIN_U1RXD_VALUE | PIN_FUNC_DEF },
	{PIN_U1RTS_REG,          PIN_U1RTS_VALUE | PIN_FUNC_DEF },
	{PIN_U1CTS_REG,          PIN_U1CTS_VALUE | PIN_FUNC_DEF },
	{PIN_PCIE_CLKREQ_L_REG,  PIN_PCIE_CLKREQ_L_VALUE | PIN_FUNC_DEF },
	{PIN_PCIE_RST_L_REG,     PIN_PCIE_RST_L_VALUE | PIN_FUNC_1 },
	{PIN_PCIE_WAKE_L_REG,    PIN_PCIE_WAKE_L_VALUE | PIN_FUNC_1 },
	{PIN_CHIP_EN_REG,        PIN_CHIP_EN_VALUE | PIN_FUNC_DEF },

	{0xffffffff, 0xffffffff}
};

static struct pm_pinfunc_tag pm_default_global_map[] = {
	{0xffffffff, 0xffffffff}
};

#define U2RXD_SEL_BIT	3
int uwp_pinmux_init(struct device *dev)
{
	int i = 0;

	__pin_enbable(TRUE);
#if defined(CONFIG_SOC_UWP5661)
	/*for uart2 need select G0/G1*/
	sys_set_bit(REG_AON_CM4_SLEEP_HOLD, U2RXD_SEL_BIT);
#endif
	for ( ; ; ) {
		struct pm_pinfunc_tag *p_func = &pm_func[i];
	/*check if search to end*/
		if (p_func->addr == PM_INVALID_VAL) {
			break;
		}
		#if defined(ANA_PIN_SUPPORT)
			if (!ANA_IS_ANA_REG(p_func->addr)) {
				sys_write32(p_func->value, p_func->addr);
			} else {
				sys_write32(p_func->value, p_func->addr);
			}
		#else
			#if defined(CONFIG_SOC_UWP5661)
				sys_write32(p_func->value, p_func->addr);
			#elif defined(CONFIG_SOC_UWP5662)
				sci_glb_set(p_func->addr, p_func->value);
			#endif
			/* CHIP_REG_SET(pm_func[i].addr,pm_func[i].value);*/
		#endif
		i++;
	}
	i = 0;
	for (;;) {
		struct pm_pinfunc_tag *p_global = &pm_default_global_map[i];
		/*check if search to end*/
		if (p_global->addr == PM_INVALID_VAL) {
			break;
		}
		/*write the value to chip*/
		 sys_write32(p_global->value, p_global->addr);
		i++;
	}
	return 0;
}

#ifdef __cpluscplus
}
#endif

