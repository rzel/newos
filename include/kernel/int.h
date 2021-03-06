/*
** Copyright 2001-2004, Travis Geiselbrecht. All rights reserved.
** Distributed under the terms of the NewOS License.
*/
#ifndef _KERNEL_INT_H
#define _KERNEL_INT_H

#include <boot/stage2.h>
#include <kernel/arch/int.h>

int int_init(kernel_args *ka);
int int_init2(kernel_args *ka);
int int_io_interrupt_handler(int vector);
int int_set_io_interrupt_handler(int vector, int (*func)(void*), void* data, const char *name);
int int_remove_io_interrupt_handler(int vector, int (*func)(void*), void* data);

void int_enable_interrupts(void);
void int_disable_interrupts(void);
void int_restore_interrupts(void);
bool int_are_interrupts_enabled(void);

enum {
	INT_NO_RESCHEDULE,
	INT_RESCHEDULE
};

#endif

