/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:06:33 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/13 19:16:07 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"

uint8 keyboard_read_input(){

    while(!(inb(0x64) & 1));
    return inb(0x60);
}

char* scan_code_strings[] = { //TODO rentre le code plus élégent
    "ERROR",   // 0x00
    "ESC",     // 0x01
    "1",       // 0x02
    "2",       // 0x03
    "3",       // 0x04
    "4",       // 0x05
    "5",       // 0x06
    "6",       // 0x07
    "7",       // 0x08
    "8",       // 0x09
    "9",       // 0x0A
    "0"        // 0x0B
};

void    print_letters(uint8 scancode) {
    
    int temp_color = WHITE;
    
    switch (scancode) {
        //first row
        case 0x0:
            print_string("ERROR", temp_color);
            break;
        case 0x01:
            print_string("ESC", temp_color);
            break;
        case 0x02:
            print_string("1", temp_color);
            break;
        case 0x03:
            print_string("2", temp_color);
            break;
        case 0x04:
            print_string("3", temp_color);
            break;
        case 0x05:
            print_string("4", temp_color);
            break;
        case 0x06:
            print_string("5", temp_color);
            break;
        case 0x07:
            print_string("6", temp_color);
            break;
        case 0x08:
            print_string("7", temp_color);
            break;
        case 0x09:
            print_string("8", temp_color);
            break;
        case 0x0A:
            print_string("9", temp_color);
            break;
        case 0x0B:
            print_string("0", temp_color);
            break;
        case 0x0C:
            print_string("-", temp_color);
            break;
        case 0x0D:
            print_string("=", temp_color);
            break;
        case 0x0E:
            ft_backspace(8, temp_color);
            break;
        //second row
        case 0x0F:
            print_string("tab", temp_color); //TODO tab
            break;
        case 0x10:
            print_string("q", temp_color);
            break;
        case 0x11:
            print_string("w", temp_color);
            break;
        case 0x12:
            print_string("e", temp_color);
            break;
        case 0x13:
            print_string("r", temp_color);
            break;
        case 0x14:
            print_string("t", temp_color);
            break;
        case 0x15:
            print_string("y", temp_color);
            break;
        case 0x16:
            print_string("u", temp_color);
            break;
        case 0x17:
            print_string("i", temp_color);
            break;
        case 0x18:
            print_string("o", temp_color);
            break;
        case 0x19:
            print_string("p", temp_color);
            break;
        case 0x1A:
            print_string("[", temp_color);
            break;
        case 0x1B:
            print_string("]", temp_color);
            break;
        case 0x1C:
            print_string("\n", temp_color); //TODO enter key
            break;
        case 0x1D:
            print_string("left control", temp_color); //TODO control
            break;
        //third row
        case 0x1E:
            print_string("a", temp_color);
            break;
        case 0x1F:
            print_string("s", temp_color);
            break;
        case 0x20:
            print_string("d", temp_color);
            break;
        case 0x21:
            print_string("f", temp_color);
            break;
        case 0x22:
            print_string("g", temp_color);
            break;
        case 0x23:
            print_string("h", temp_color);
            break;
        case 0x24:
            print_string("j", temp_color);
            break;
        case 0x25:
            print_string("k", temp_color);
            break;
        case 0x26:
            print_string("l", temp_color);
            break;
        case 0x27:
            print_string(";", temp_color);
            break;
        case 0x28:
            print_string("'", temp_color);
            break;
        case 0x29:
            print_string("`", temp_color);
            break;
        //fourth row
        case 0x2A:
            print_string("left shift", temp_color); //TODO using left shift for uppercase
            break;
        case 0x2B:
            print_string("\\", temp_color);
            break;
        case 0x2C:
            print_string("z", temp_color);
            break;
        case 0x2D:
            print_string("x", temp_color);
            break;
        case 0x2E:
            print_string("c", temp_color);
            break;
        case 0x2F:
            print_string("v", temp_color);
            break;
        case 0x30:
            print_string("b", temp_color);
            break;
        case 0x31:
            print_string("n", temp_color);
            break;
        case 0x32:
            print_string("m", temp_color);
            break;
        case 0x33:
            print_string(",", temp_color);
            break;
        case 0x34:
            print_string(".", temp_color);
            break;
        case 0x35:
            print_string("/", temp_color);
            break;
        case 0x36:
            print_string("right shift", temp_color); //TODO using right shift for uppercase
            break;
        case 0x37:
            // print_string(",", temp_color); //TODO numpad *
            break;
        case 0x38:
            print_string("left alt", temp_color); //TODO using left alt
            break;
        case 0x39:
            print_string(" ", temp_color);
            break;
        case 0x3A:
            print_string("CAPS LOCK", temp_color); //TODO using caps lock
            break;

        default:
            if (scancode <= 0x7f)
                ft_printerr("*");
            break;
    }
}

void    keyboard_init() {
    
    uint8 scancode = keyboard_read_input();
    print_letters(scancode);
}