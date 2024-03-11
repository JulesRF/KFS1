/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:55:40 by rdel-agu          #+#    #+#             */
/*   Updated: 2024/03/11 13:04:47 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "kfs.h"

# define KEYBOARD_PORT 0x60
# define RELEASED(keycode) keycode & 0x80
# define GET_FROM_RELEASED(keycode) keycode ^ 0x80

uint16 keyboard_handler( void );

#endif