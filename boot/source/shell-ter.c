/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell-ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:33:55 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/15 15:46:09 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"
#include "include/io.h"

uint16 get_cursor_position(void)
{
    uint16 pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16)inb(0x3D5)) << 8;
    return pos;
}

void    modify_cursor_position( uint16 pos ){

    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8) ((pos >> 8) & 0xFF));
}

void shell_ter( void ) {

    int color42 = BROWN;

    print_string("\n", color42);
    print_string("/* ************************************************************************** */", color42);
    print_string("/*                                                                            */", color42);
    print_string("/*                                                        :::      ::::::::   */", color42);
    print_string("/*   Welcome to KFS-1 !                                 :+:      :+:    :+:   */", color42);
    print_string("/*                                                    +:+ +:+         +:+     */", color42);
    print_string("/*   By: jroux-fo & rdel-agu                        +#+  +:+       +#+        */", color42);
    print_string("/*                                                +#+#+#+#+#+   +#+           */", color42);
    print_string("/*   CPU MODEL :                                        #+#    #+#             */", color42);
    print_string("/*   Updated: 2024/03/15 14:44:45 by rdel-agu         ###   ###########       */", color42);
    print_string("/*                                                                            */", color42);
    print_string("/* ************************************************************************** */\n", color42);

    print_string("kfs-1 > ", L_BLUE);
    
    while(69) {
        
        // else if (scancode <= 0x39 + 0x80) {
            
        //     print_string("Key up", WHITE);
        //     print_char(scancode - 0x80, WHITE);
        // }
        
        // DELETE THE CURSOR
        // outb(0x3D4, 0x0A);
	    // outb(0x3D5, 0x20);

        
        keyboard_init();
        uint16 pos = vga_index[screen - 1]; //TODO imprimer un espace toujours devant le dernier char
        modify_cursor_position(pos);        // pour pouvoir afficher le curseur devant
       

    }
}