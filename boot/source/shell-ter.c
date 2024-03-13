/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell-ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:33:55 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/13 18:23:38 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/kfs.h"
#include "include/io.h"



void shell_ter( void ) {

    // print_char(scancode, WHITE);
    while(69) {
        
        // else if (scancode <= 0x39 + 0x80) {
            
        //     print_string("Key up", WHITE);
        //     print_char(scancode - 0x80, WHITE);
        // }
        keyboard_init();

    }
}