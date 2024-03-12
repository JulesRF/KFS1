/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:11:13 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/12 15:32:40 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"
#include "include/interrupts.h"

idt_gate_t	idt[256];
idt_register_t idt_reg;
isr_t interrupt_handlers[256];

char *exception_messages[] = {

    "Division by zero",
    "Debug",
    "NMI",
    "Breakpoint",
    "Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Coprocessor not available",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Invalid Task State Segment",
    "Segment not present",
    "Stack Segment Fault",
    "General Protection Fault",
    "Page Fault",
    "Reserved"
};

void isr_handler(registers_t *r) {

    print_string(exception_messages[r->int_no] + '\n', RED, 0);
}

void load_idt( void ) {

    idt_reg.base = (uint32) &idt;
    idt_reg.limit = 256 * sizeof(idt_gate_t) - 1; //256 = sizeof idt
    asm volatile("lidt (%0)" : : "r" (&idt_reg));
}

void irq_handler(registers_t *r) {

    if (interrupt_handlers[r->int_no] != 0) {
        isr_t handler = interrupt_handlers[r->int_no];
        handler(r);
    }

    port_byte_out(0x20, 0x20); // primary EOI
    if (r->int_no < 40) {
        port_byte_out(0xA0, 0x20); // secondary EOI
    }
}

void register_interrupt_handler(uint8 n, isr_t handler) {
    
    interrupt_handlers[n] = handler;
}

#define LOW_16(address) (uint16)((address) & 0xFFFF)
#define HIGH_16(address) (uint16)(((address) >> 16) & 0xFFFF)


void	set_idt_gate(int n, uint32 handler) {

	idt[n].low_offset = LOW_16(handler);
	idt[n].high_offset = HIGH_16(handler);

	idt[n].selector = 0x08; // see GDT
	idt[n].always0 = 0;
	// 0x8E = 1  00 0 1  110
	//        P DPL 0 D Type
	idt[n].flags = 0x8E;
}

void isr0(void){}
void isr1(void){}
void isr2(void){}
void isr3(void){}
void isr4(void){}
void isr5(void){}
void isr6(void){}
void isr7(void){}
void isr8(void){}
void isr9(void){}
void isr10(void){}
void isr11(void){}
void isr12(void){}
void isr13(void){}
void isr14(void){}
void isr15(void){}
void isr16(void){}
void isr17(void){}
void isr18(void){}
void isr19(void){}
void isr20(void){}
void isr21(void){}
void isr22(void){}
void isr23(void){}
void isr24(void){}
void isr25(void){}
void isr26(void){}
void isr27(void){}
void isr28(void){}
void isr29(void){}
void isr30(void){}
void isr31(void){}

void irq0(void){}
void irq1(void){}
void irq2(void){}
void irq3(void){}
void irq4(void){}
void irq5(void){}
void irq6(void){}
void irq7(void){}
void irq8(void){}
void irq9(void){}
void irq10(void){}
void irq11(void){}
void irq12(void){}
void irq13(void){}
void irq14(void){}
void irq15(void){}

void	isr_install( void ) {

    set_idt_gate(0, (uint32)isr0);
    set_idt_gate(1, (uint32)isr1);
    set_idt_gate(2, (uint32)isr2);
    set_idt_gate(3, (uint32)isr3);
    set_idt_gate(4, (uint32)isr4);
    set_idt_gate(5, (uint32)isr5);
    set_idt_gate(6, (uint32)isr6);
    set_idt_gate(7, (uint32)isr7);
    set_idt_gate(8, (uint32)isr8);
    set_idt_gate(9, (uint32)isr9);
    set_idt_gate(10, (uint32)isr10);
    set_idt_gate(11, (uint32)isr11);
    set_idt_gate(12, (uint32)isr12);
    set_idt_gate(13, (uint32)isr13);
    set_idt_gate(14, (uint32)isr14);
    set_idt_gate(15, (uint32)isr15);
    set_idt_gate(16, (uint32)isr16);
    set_idt_gate(17, (uint32)isr17);
    set_idt_gate(18, (uint32)isr18);
    set_idt_gate(19, (uint32)isr19);
    set_idt_gate(20, (uint32)isr20);
    set_idt_gate(21, (uint32)isr21);
    set_idt_gate(22, (uint32)isr22);
    set_idt_gate(23, (uint32)isr23);
    set_idt_gate(24, (uint32)isr24);
    set_idt_gate(25, (uint32)isr25);
    set_idt_gate(26, (uint32)isr26);
    set_idt_gate(27, (uint32)isr27);
    set_idt_gate(28, (uint32)isr28);
    set_idt_gate(29, (uint32)isr29);
    set_idt_gate(30, (uint32)isr30);
    set_idt_gate(31, (uint32)isr31);

    // ICW1
    port_byte_out(0x20, 0x11);
    port_byte_out(0xA0, 0x11);

    // ICW2
    port_byte_out(0x21, 0x20);
    port_byte_out(0xA1, 0x28);

    // ICW3
    port_byte_out(0x21, 0x04);
    port_byte_out(0xA1, 0x02);

    // ICW4
    port_byte_out(0x21, 0x01);
    port_byte_out(0xA1, 0x01);

    // OCW1
    port_byte_out(0x21, 0x0);
    port_byte_out(0xA1, 0x0);

    // IRQ ISRs (primary PIC)
    set_idt_gate(32, (uint32)irq0);
    set_idt_gate(33, (uint32)irq1);
    set_idt_gate(34, (uint32)irq2);
    set_idt_gate(35, (uint32)irq3);
    set_idt_gate(36, (uint32)irq4);
    set_idt_gate(37, (uint32)irq5);
    set_idt_gate(38, (uint32)irq6);
    set_idt_gate(39, (uint32)irq7);
    set_idt_gate(39, (uint32)irq7);

    // IRQ ISRs (secondary PIC)
    set_idt_gate(40, (uint32)irq8);
    set_idt_gate(41, (uint32)irq9);
    set_idt_gate(42, (uint32)irq10);
    set_idt_gate(43, (uint32)irq11);
    set_idt_gate(44, (uint32)irq12);
    set_idt_gate(45, (uint32)irq13);
    set_idt_gate(46, (uint32)irq14);
    set_idt_gate(47, (uint32)irq15);

	load_idt();
}
