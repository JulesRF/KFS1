/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:06:33 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/19 13:47:21 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"

int     isShiftPressed = 0;
int     isCapsPressed  = 0;
int     isCtrlPressed  = 0;

uint8 keyboard_read_input(){

    while(!(inb(0x64) & 1));
    return inb(0x60);
}

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
                ""/*L_ALT*/, " "/*SPACE*/, "" /*CAPS_LOCK*/
    };
    
    char* scancode_shift[] = {

        "ERROR",
        ""/*ESC*/, "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", ""/*BACKSPACE*/,
        ""/*TAB*/,      "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "\n",
        ""/*L_CTRL*/,     "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~",
        ""/*L_SHFT*/, "|", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", ""/*R_SHFT*/, "*"/*NUMPAD STAR*/,
                ""/*L_ALT*/, " "/*SPACE*/, "" /*CAPS_LOCK*/  
    };

    // Check if scancode is within valid range
    if (scancode <= 0x3A) {

        if ((scancode == 0x2A) || scancode == 0x36 )    //SHIFT PRESS
            isShiftPressed = 1;
        if (scancode == 0x1D)                           //LEFT CONTROL PRESS
            isCtrlPressed = 1;
        if (scancode == 0x0E) {                         //BACKSPACE PRESS
            // TODO faire en sorte de ne pas pouvoir retirer le kfs-1 >
            ft_backspace();
        }
        if (scancode == 0x3A) {                         //CAPSLOCK PRESS

            if (isCapsPressed == 1)
                isCapsPressed = 0;
            else
                isCapsPressed = 1;
        }
        if (isCtrlPressed == 1) {
            if (scancode == 0x26)
                clear_screen(0);                        //TODO faire revenir le clearscreen au début et afficher le kfs-1 >
            if (scancode == 0x0E)
                ft_ctrl_backspace();
        }
        else if (isShiftPressed == 1 || isCapsPressed == 1)   //SHIFT HANDLER
            print_string(scancode_shift[scancode], temp_color);
        else
            print_string(scancode_strings[scancode], temp_color);

        if (scancode == 0x1C)
            print_string("kfs-1 > ", L_BLUE);

    } else if (scancode >= 0x3B && scancode <=0x44 ) {  //F1-F10 PRESS
        
        if (scancode == 0x3B) { // F1
           
        }
        if (scancode == 0x3C) { // F2

        }
    } else if(scancode <= 0x39 + 0x80) {                //KEY RELEASE
        
        if ((scancode - 0x80 == 0x2A) || (scancode - 0x80 == 0x36)) // SHIFT RELEASE
            isShiftPressed = 0;
        if (scancode - 0x80 == 0x1D)                    // CTRL RELEASE
            isCtrlPressed = 0;
    } else {                                            //scancode debug

        // print_string("Unknown key\n", temp_color);
        // ft_putnbr_hex(scancode, RED);
    }
}

void    keyboard_init() {
    
    uint8 scancode = keyboard_read_input();
    print_letters(scancode);
}
