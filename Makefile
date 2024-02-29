# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 14:00:09 by rdel-agu          #+#    #+#              #
#    Updated: 2024/02/29 14:08:05 by rdel-agu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LD = ld

NASM = nasm

CFLAGS = -fno-builtin \
		 -fno-exception \
		 -fno-stack-protector \
		 -fno-rtti \
		 -nostdlib \
		 -nodefaultlibs
		 -g3

all: 