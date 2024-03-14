/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:06:33 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/14 17:49:14 by rdel-agu         ###   ########.fr       */
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
    
    // switch (scancode) {
    //     //first row
    //     case 0x0:
    //         print_string("ERROR", temp_color);
    //         break;
    //     case 0x01:
    //         print_string("ESC", temp_color);
    //         break;
    //     case 0x02:
    //         if (isShiftPressed == 0)
    //             print_string("1", temp_color);
    //         else
    //             print_string("!", temp_color);
    //         break;
    //     case 0x03:
    //         if (isShiftPressed == 0)
    //             print_string("2", temp_color);
    //         else
    //             print_string("@", temp_color);
    //         break;
    //     case 0x04:
    //         if (isShiftPressed == 0)
    //             print_string("3", temp_color);
    //         else
    //             print_string("#", temp_color);
    //         break;
    //     case 0x05:
    //         if (isShiftPressed == 0)
    //             print_string("4", temp_color);
    //         else
    //             print_string("$", temp_color);
    //         break;
    //     case 0x06:
    //         if (isShiftPressed == 0)
    //             print_string("5", temp_color);
    //         else
    //             print_string("%", temp_color);
    //         break;
    //     case 0x07:
    //         if (isShiftPressed == 0)
    //             print_string("6", temp_color);
    //         else
    //             print_string("^", temp_color);
    //         break;
    //     case 0x08:
    //         if (isShiftPressed == 0)
    //             print_string("7", temp_color);
    //         else
    //             print_string("&", temp_color);
    //         break;
    //     case 0x09:
    //         if (isShiftPressed == 0)
    //             print_string("8", temp_color);
    //         else
    //             print_string("*", temp_color);
    //         break;
    //     case 0x0A:
    //         if (isShiftPressed == 0)
    //             print_string("9", temp_color);
    //         else
    //             print_string("(", temp_color);
    //         break;
    //     case 0x0B:
    //         if (isShiftPressed == 0)
    //             print_string("0", temp_color);
    //         else
    //             print_string(")", temp_color);
    //         break;
    //     case 0x0C:
    //         if (isShiftPressed == 0)
    //             print_string("-", temp_color);
    //         else
    //             print_string("_", temp_color);
    //         break;
    //     case 0x0D:
    //         if (isShiftPressed == 0)
    //             print_string("=", temp_color);
    //         else
    //             print_string("+", temp_color);
    //         break;
    //     case 0x0E:
    //         ft_backspace(8, temp_color);
    //         break;
    //     //second row
    //     case 0x0F:
    //         print_string("tab", temp_color); //TODO tab
    //         break;
    //     case 0x10:
    //         print_string("q", temp_color);
    //         break;
    //     case 0x11:
    //         print_string("w", temp_color);
    //         break;
    //     case 0x12:
    //         print_string("e", temp_color);
    //         break;
    //     case 0x13:
    //         print_string("r", temp_color);
    //         break;
    //     case 0x14:
    //         print_string("t", temp_color);
    //         break;
    //     case 0x15:
    //         print_string("y", temp_color);
    //         break;
    //     case 0x16:
    //         print_string("u", temp_color);
    //         break;
    //     case 0x17:
    //         print_string("i", temp_color);
    //         break;
    //     case 0x18:
    //         print_string("o", temp_color);
    //         break;
    //     case 0x19:
    //         print_string("p", temp_color);
    //         break;
    //     case 0x1A:
    //         print_string("[", temp_color);
    //         break;
    //     case 0x1B:
    //         print_string("]", temp_color);
    //         break;
    //     case 0x1C:
    //         print_string("\n", temp_color); //TODO enter key
    //         break;
    //     case 0x1D:
    //         print_string("left control", temp_color); //TODO control
    //         break;
    //     //third row
    //     case 0x1E:
    //         print_string("a", temp_color);
    //         break;
    //     case 0x1F:
    //         print_string("s", temp_color);
    //         break;
    //     case 0x20:
    //         print_string("d", temp_color);
    //         break;
    //     case 0x21:
    //         print_string("f", temp_color);
    //         break;
    //     case 0x22:
    //         print_string("g", temp_color);
    //         break;
    //     case 0x23:
    //         print_string("h", temp_color);
    //         break;
    //     case 0x24:
    //         print_string("j", temp_color);
    //         break;
    //     case 0x25:
    //         print_string("k", temp_color);
    //         break;
    //     case 0x26:
    //         print_string("l", temp_color);
    //         break;
    //     case 0x27:
    //         print_string(";", temp_color);
    //         break;
    //     case 0x28:
    //         print_string("'", temp_color);
    //         break;
    //     case 0x29:
    //         print_string("`", temp_color);
    //         break;
    //     //fourth row
    //     case 0x2A:
    //         // print_string("left shift", temp_color); //TODO using left shift for uppercase
    //         isShiftPressed = 1;
    //         break;
    //     case 0x2B:
    //         print_string("\\", temp_color);
    //         break;
    //     case 0x2C:
    //         print_string("z", temp_color);
    //         break;
    //     case 0x2D:
    //         print_string("x", temp_color);
    //         break;
    //     case 0x2E:
    //         print_string("c", temp_color);
    //         break;
    //     case 0x2F:
    //         print_string("v", temp_color);
    //         break;
    //     case 0x30:
    //         print_string("b", temp_color);
    //         break;
    //     case 0x31:
    //         print_string("n", temp_color);
    //         break;
    //     case 0x32:
    //         print_string("m", temp_color);
    //         break;
    //     case 0x33:
    //         print_string(",", temp_color);
    //         break;
    //     case 0x34:
    //         print_string(".", temp_color);
    //         break;
    //     case 0x35:
    //         print_string("/", temp_color);
    //         break;
    //     case 0x36:
    //         // print_string("right shift", temp_color); //TODO using right shift for uppercase
    //         isShiftPressed = 1;
    //         break;
    //     case 0x37:
    //         // print_string(",", temp_color); //TODO numpad *
    //         break;
    //     case 0x38:
    //         print_string("left alt", temp_color); //TODO using left alt
    //         break;
    //     case 0x39:
    //         print_string(" ", temp_color);
    //         break;
    //     case 0x3A:
    //         print_string("CAPS LOCK", temp_color); //TODO using caps lock
    //         break;

    //     default:
    //         if (scancode <= 0x7f)
    //             ft_printerr("*");
    //         else if (scancode <= 0x39 + 0x80) {
    //             // print_string("key up", temp_color);
    //             // print_letters(scancode - 0x80);
    //             // ft_putnbr_hex(scancode - 0x80, WHITE);
    //             if ((scancode - 0x80 == 0x2A) || (scancode - 0x80 == 0x36))
    //                 isShiftPressed = 0;
    //         }
    //         break;
    // }

    char* scancode_strings[] = {

        "ERROR",
        "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", ""/*BACKSPACE*/,
        "TAB",      "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\n",
        "L_CTRL",     "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`",
        ""/*L_SHFT*/, "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", ""/*R_SHFT*/, "*"/*NUMPAD STAR*/,
                "L_ALT", " "/*SPACE*/, "CAPS_LOCK"

    };
    
    char* scancode_shift[] = {

        "ERROR",
        "ESC", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", ""/*BACKSPACE*/,
        "TAB",      "Q", "W", "É", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "\n",
        ""/*L_CTRL*/,     "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~",
        ""/*L_SHFT*/, "|", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", ""/*R_SHFT*/, "*"/*NUMPAD STAR*/,
                "L_ALT", " "/*SPACE*/, "CAPS_LOCK", 
        
    };

     // Check if scancode is within valid range
    if (scancode <= 0x3A) {

        if ((scancode == 0x2A) || scancode == 0x36 )
            isShiftPressed = 1;
        if (scancode == 0x0E)
            ft_backspace();
    
        if (isShiftPressed == 0)
            print_string(scancode_strings[scancode], temp_color);
        else
            print_string(scancode_shift[scancode], temp_color);
    } else if (scancode <= 0x39 + 0x80){
        
        if ((scancode - 0x80 == 0x2A) || (scancode - 0x80 == 0x36))
            isShiftPressed = 0;
    } else {
        print_string("Unknown key\n", temp_color);
        ft_putnbr_hex(scancode - 0x80, RED);
    }
}

void    keyboard_init() {
    
    uint8 scancode = keyboard_read_input();
    print_letters(scancode);
}