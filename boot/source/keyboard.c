/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:06:33 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/15 15:40:24 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"

uint8 keyboard_read_input(){

    while(!(inb(0x64) & 1));
    return inb(0x60);
}


int     isShiftPressed = 0;

void    print_letters(uint8 scancode) {
    
    int     temp_color = WHITE;

    // ESC =        0x01
    // BACKSPACE =  0x0E
    // TAB =        0x0F
    // L_CTRL =     0x1D
    // L_SHFT =     0x2A
    // R_SHFT =     0x36
    // L_ALT =      0x38

    char* scancode_strings[] = {

        "ERROR",
        ""/*ESC*/, "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", ""/*BACKSPACE*/,
        ""/*TAB*/,      "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\n",
        ""/*L_CTRL*/,     "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`",
        ""/*L_SHFT*/, "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", ""/*R_SHFT*/, "*"/*NUMPAD STAR*/,
                "L_ALT", " "/*SPACE*/, "CAPS_LOCK"

    };
    
    char* scancode_shift[] = {

        "ERROR",
        ""/*ESC*/, "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", ""/*BACKSPACE*/,
        ""/*TAB*/,      "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "\n",
        ""/*L_CTRL*/,     "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~",
        ""/*L_SHFT*/, "|", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", ""/*R_SHFT*/, "*"/*NUMPAD STAR*/,
                ""/*L_ALT*/, " "/*SPACE*/, "CAPS_LOCK", 
        
    };

     // Check if scancode is within valid range
    if (scancode <= 0x3A) {

        if ((scancode == 0x2A) || scancode == 0x36 ) // TODO fonctionnement du CAPSLOCK avec l'interraction du shift
            isShiftPressed = 1;
        if (scancode == 0x0E)
            ft_backspace();
        if (isShiftPressed == 0)
            print_string(scancode_strings[scancode], temp_color);
        else
            print_string(scancode_shift[scancode], temp_color);
        if (scancode == 0x1C)
            print_string("kfs-1 > ", L_BLUE);
    } else if (scancode <= 0x39 + 0x80){
        
        if ((scancode - 0x80 == 0x2A) || (scancode - 0x80 == 0x36))
            isShiftPressed = 0;
    } else {
        print_string("Unknown key\n", temp_color);
        ft_putnbr_hex(scancode, RED);
    }
}

void    keyboard_init() {
    
    uint8 scancode = keyboard_read_input();
    print_letters(scancode);
}