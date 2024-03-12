/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:57:14 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/12 15:54:35 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"

    int i = 0;

// uint16 keyboard_handler( void ) {

//     uint8 scancode;


//     if (i == 0) {
//         print_string("Hello world!", RED);
//         i++;
//     }
//     scancode = inb(KEYBOARD_PORT);
//     if (scancode == 0x1)
//             i = 0;
//     else
//         outb(KEYBOARD_PORT, 0);
//     // if (RELEASED(scancode)) {
        
       
//     //     return (0);
//     // }
//     // else {
//     //     outb(KEYBOARD_PORT, 0);
        
//     // }
    
//     return (scancode);
// }

void print_letter(uint8 scancode) {
    switch (scancode) {
        case 0x0:
            print_string("ERROR", WHITE);
            break;
        case 0x1:
            print_string("ESC", WHITE);
            break;
        case 0x2:
            print_string("1", WHITE);
            break;
        case 0x3:
            print_string("2", WHITE);
            break;
        case 0x39:
            print_string("Space", WHITE);
            break;
        default:
            if (scancode <= 0x7f) {
                print_string("Unknown key down", WHITE);
            } else if (scancode <= 0x39 + 0x80) {
                print_string("key up ", WHITE);
                print_letter(scancode - 0x80);
            } else {
                print_string("Unknown key up", WHITE);
            }
            break;
    }
}

static void keyboard_callback(registers_t *regs) {

    (void)regs;

    print_string("hello world \n", RED);
    
    uint8 scancode = inb(0x60);
    if (scancode != 0)
        print_letter(scancode);
}

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback);
}
