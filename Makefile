# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 14:00:09 by rdel-agu          #+#    #+#              #
#    Updated: 2024/02/29 15:56:28 by rdel-agu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kfs

ISO = $(NAME).iso

CC = gcc

LD = ld

NASM = nasm

BOOT = boot/boot.asm

BOOT_OBJ = boot/boot.o

CFLAGS = -fno-builtin \
		 -fno-exception \
		 -fno-stack-protector \
		 -fno-rtti \
		 -nostdlib \
		 -nodefaultlibs \
		 -g3

.PHONY: all run 

all: boot

boot: $(BOOT)
		@echo " \033[0;31mAssembling $(NAME)...\033[0m"
		@$(NASM) -f elf32 $(BOOT) -o $(BOOT_OBJ)
		@echo " \033[0;32mSuccess\033[0m"

# clean:
		

# fclean:
		

run: #requires creation of ISO to run
		qemu-system-i386 -cdrom $(ISO)