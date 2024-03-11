/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:35:00 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/11 17:57:35 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"

uint8 inb(uint16 port){
    uint8 ret;
    asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

void outb(uint16 port, uint8 value){
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

uint8 port_byte_in(uint16 port) {
    uint8 result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void port_byte_out(uint16 port, uint8 data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}