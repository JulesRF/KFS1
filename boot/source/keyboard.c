/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:57:14 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/11 13:09:29 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"

uint16 keyboard_handler( void ) {

    uint8 scancode;

    scancode = inb(KEYBOARD_PORT);
    if (RELEASED(scancode)) {
        
        if (scancode == 0x01)
            
        return (0);
    }
    else {
        outb(KEYBOARD_PORT, 0);
        
    }
    
    return (0);
}
