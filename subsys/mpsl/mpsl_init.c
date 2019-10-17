/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <init.h>
#include <irq.h>
#include <kernel.h>
#include <mpsl.h>

#define MPSL_LOW_PRIO_IRQ SWI5_IRQn

static void m_assert_handler(const char *const file, const u32_t line)
{
	k_oops();
}

static int mpsl_lib_init(struct device *dev)
{
	ARG_UNUSED(dev);

	int err = 0;
	mpsl_clock_lf_cfg_t clock_cfg;

#ifdef CONFIG_CLOCK_CONTROL_NRF_K32SRC_RC
	clock_cfg.source = MPSL_CLOCK_LF_SRC_RC;
#elif CONFIG_CLOCK_CONTROL_NRF_K32SRC_XTAL
	clock_cfg.source = MPSL_CLOCK_LF_SRC_XTAL;
#elif CONFIG_CLOCK_CONTROL_NRF_K32SRC_SYNTH
	clock_cfg.source = MPSL_CLOCK_LF_SRC_SYNTH;
#else
#error "Clock source is not supported or not defined"
#endif

	clock_cfg.rc_ctiv = MPSL_RECOMMENDED_RC_CTIV;
	clock_cfg.rc_temp_ctiv = MPSL_RECOMMENDED_RC_TEMP_CTIV;

	err = mpsl_init(&clock_cfg, MPSL_LOW_PRIO_IRQ, m_assert_handler);
	if (err) {
		return err;
	}

	irq_enable(MPSL_LOW_PRIO_IRQ);

	return 0;
}

SYS_INIT(mpsl_lib_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
