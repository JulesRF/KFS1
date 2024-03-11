/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:06:51 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/11 11:43:12 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int    uint32;

uint8   inb(uint16 port);
void    outb(uint16 port, uint8 value);

#endif