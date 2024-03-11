/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:06:51 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/11 17:41:00 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int    uint32;

uint8           inb(uint16 port);
void            outb(uint16 port, uint8 value);

unsigned char   port_byte_in(unsigned short port);
void            port_byte_out(unsigned short port, unsigned char data);

#endif