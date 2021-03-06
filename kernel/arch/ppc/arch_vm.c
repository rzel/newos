/*
** Copyright 2001-2004, Travis Geiselbrecht. All rights reserved.
** Distributed under the terms of the NewOS License.
*/
#include <kernel/kernel.h>
#include <boot/stage2.h>

#include <kernel/arch/vm.h>
#include <string.h>

int arch_vm_init(kernel_args *ka)
{
	return 0;
}

int arch_vm_init2(kernel_args *ka)
{
	int bats[8];
	int i;

#if 0
	// print out any bat mappings
	getibats(bats);
	dprintf("ibats:\n");
	for(i = 0; i < 4; i++)
		dprintf("0x%x 0x%x\n", bats[i*2], bats[i*2+1]);
	getdbats(bats);
	dprintf("dbats:\n");
	for(i = 0; i < 4; i++)
		dprintf("0x%x 0x%x\n", bats[i*2], bats[i*2+1]);
#endif

#if 1
	// turn off the first 2 BAT mappings (3 & 4 are used by the lower level code)
	getibats(bats);
	memset(bats, 0, 2 * 2);
	setibats(bats);
	getdbats(bats);
	memset(bats, 0, 2 * 2);
	setdbats(bats);
#endif
#if 0
	// just clear the first BAT mapping (0 - 256MB)
	dprintf("msr 0x%x\n", getmsr());
	{
		unsigned int reg;
		asm("mr	%0,1" : "=r"(reg));
		dprintf("sp 0x%x\n", reg);
	}
	dprintf("ka %p\n", ka);

	getibats(bats);
	dprintf("ibats:\n");
	for(i = 0; i < 4; i++)
		dprintf("0x%x 0x%x\n", bats[i*2], bats[i*2+1]);
	bats[0] = bats[1] = 0;
	setibats(bats);
	getdbats(bats);
	dprintf("dbats:\n");
	for(i = 0; i < 4; i++)
		dprintf("0x%x 0x%x\n", bats[i*2], bats[i*2+1]);
	bats[0] = bats[1] = 0;
	setdbats(bats);
#endif
	return 0;
}

int arch_vm_init_existing_maps(kernel_args *ka)
{
	addr_t temp;

	// create a region for the framebuffer
	temp = ka->fb.mapping.start;
	vm_create_anonymous_region(vm_get_kernel_aspace_id(), "framebuffer", &temp, REGION_ADDR_EXACT_ADDRESS,
		ka->fb.mapping.size, REGION_WIRING_WIRED_ALREADY, LOCK_RW|LOCK_KERNEL);

	return NO_ERROR;
}

int arch_vm_init_endvm(kernel_args *ka)
{
	return NO_ERROR;
}

void arch_vm_aspace_swap(vm_address_space *aspace)
{
}
