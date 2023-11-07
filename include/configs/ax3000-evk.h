/*

Copyright (c) 2021-22 Axiado Corporation (or its affiliates). All rights reserved.
Use, modification and redistribution of this file is subject to your possession
of a valid End User License Agreement (EULA) for the Axiado Product of which
these sources are part of and your compliance with all applicable terms and
conditions of such licence agreement.
*/

#ifndef	__AX3000_EVK_H
#define __AX3000_EVK_H

#include <linux/sizes.h>

#define CONFIG_ARMV8_SWITCH_TO_EL1

#define CONFIG_GICV3
#define GICD_BASE		0x80300000
#define GICR_BASE		0x80380000


#define SYS_TIMER_CTRL   0x8A020000
#define SYS_TIMER_ENABLE    0x1
#define COUNTER_FREQUENCY    62500000

#define CONFIG_NR_CPUS			4

#define CONFIG_SYS_SDRAM_BASE		0x3C000000
#define CONFIG_SYS_SDRAM_SIZE 		16
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + SZ_1M)
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END          ((CONFIG_SYS_SDRAM_SIZE - 3) << 20)

#define CONFIG_SYS_LOAD_ADDR		0x3D000000

#define CONFIG_SYS_CBSIZE		SZ_1K
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
		sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		64
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE

#ifndef CONFIG_CPU_FREQ_HZ
# define CONFIG_CPU_FREQ_HZ 10000000
#endif
#define CONFIG_SYS_MALLOC_LEN  (128 << 10) /* Reserve 128 kB for malloc() */

#define CONFIG_CPU_ARMV8

#define CONFIG_SYS_BAUDRATE_TABLE \
	{ 4800, 9600, 19200, 38400, 57600, 115200 }

#define CONFIG_EXTRA_ENV_SETTINGS 		\
	"bootm_size=0x20000000\0" \
	"fdtaddr=0x3EF00000\0" \
	"loadaddr=0x3D000000\0"	\
	"scratchpad1=80620804\0" \
	"ubootsuccess=54d\0" \
	"ubootstatus=mw.l ${scratchpad1} ${ubootsuccess}\0"

#define CONFIG_BOOTCOMMAND \
	"run ubootstatus; booti ${loadaddr} - ${fdtaddr}"

#endif /* __AX3000_EVK_H */
