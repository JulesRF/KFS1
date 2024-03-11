/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupts.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:54 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/11 17:43:29 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERRUPTS_H
# define INTERRUPTS_H

# include "kfs.h"

typedef	struct  {
	uint16	low_offset;
	uint16	selector;
	uint8	always0;
	uint8	flags;
	uint16	high_offset;
}	__attribute__((packed))	idt_gate_t;

typedef	struct	{
	// data segment selector
	uint32	ds;
	// general purpose registers pushed by pusha
	uint32	edi;
	uint32	esi;
	uint32	ebp;
	uint32	esp;
	uint32	ebx;
	uint32	edx;
	uint32	ecx;
	uint32	eax;
	// pushed by isr procedure
	uint32	int_no;
	uint32	err_code;
	// pushed by CPU automatically
	uint32	eip;
	uint32	cs;
	uint32	eflags;
	uint32	useresp;
	uint32	ss;
}	registers_t;

typedef struct {
    uint16 limit;
    uint32 base;
} __attribute__((packed)) idt_register_t;

typedef void (*t_interrupt_handler_func_ptr)(registers_t);

void    register_interrupt_handler( uint8 n, t_interrupt_handler_func_ptr handler);

extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);

extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);

void isr_install( void );

#endif