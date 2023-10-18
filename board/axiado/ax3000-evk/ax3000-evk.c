/*

Copyright (c) 2021-22 Axiado Corporation (or its affiliates). All rights reserved.
Use, modification and redistribution of this file is subject to your possession
of a valid End User License Agreement (EULA) for the Axiado Product of which
these sources are part of and your compliance with all applicable terms and
conditions of such licence agreement.
*/


#include <common.h>
#include <config.h>
#include <dm.h>
#include <env.h>
#include <init.h>
#include <memalign.h>
#include <asm/global_data.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>

static struct mm_region axiado_ax200_mem_map[] = {
       {
                .virt = 0x3C000000UL,
                .phys = 0x3C000000UL,
                .size = 0x01000000UL,
                .attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
                         PTE_BLOCK_INNER_SHARE 
        }, {
                0,
        }
};

struct mm_region *mem_map = axiado_ax200_mem_map;

#ifdef CONFIG_MISC_INIT_R
/**
 * @brief Configure Board Specific parts
 *
 * @param void
 *
 * @return int
 */
int misc_init_r(void)
{
	return 0;
}
#endif

/**
 * @brief Name of the device tree to be loaded from the Flattened Image Tree (FIT)
 *        (Not used) 
 *
 * @param void
 *
 * @return void
 */
int board_fit_config_name_match(const char *name) 
{
	return 0;
}

/**
 * @brief board specific dram initialization 
 *
 * @param void
 *
 * @return void
 */
int dram_init(void)
{
	gd->ram_size = get_ram_size(0, mem_map[0].size);
	return 0;
}

int timer_init(void)
{
	writel(SYS_TIMER_ENABLE, SYS_TIMER_CTRL);
	return 0;
}
/**
 * @brief board specific initialization 
 *
 * @param void
 *
 * @return void
 */
int board_init(void)
{
	return 0;
}

/**
 * @brief board specific reset 
 *
 * @param void
 *
 * @return void
 */
void reset_cpu(void)
{
	return;
}


/**
 * @brief SOC specific CPU Setup 
 *
 * @param void
 *
 * @return void
 */
int mach_cpu_init(void)
{
	return 0;
}
