# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 14:00:09 by rdel-agu          #+#    #+#              #
#    Updated: 2024/02/29 17:10:47 by rdel-agu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kfs

ISO = $(NAME).iso

CC = gcc

LD = ld

NASM = nasm

BOOT = boot/boot.asm

BOOT_OBJ = boot/boot.o

RM = rm

CFLAGS = -fno-builtin \
		 -fno-exception \
		 -fno-stack-protector \
		 -fno-rtti \
		 -nostdlib \
		 -nodefaultlibs \
		 -Wall\
		 -Werror\
		 -Wextra\
		 -g3

.PHONY: all run boot

all: boot

%.o : %.asm
	@$(NASM) -f elf32 -g -F dwarf $< -o $@

	
boot : $(BOOT)
	@echo " \033[0;31mAssembling $(BOOT)...\033[0m"
	@$(NASM) -f elf32 $(BOOT) -o $(BOOT_OBJ)
	@echo " \033[0;32mSuccess\033[0m"



link:


iso:


clean:
	@echo " \033[0;31mCleaning objects!\033[30m"
	$(RM) -f $(BOOT_OBJ) "\033[0m"
	@echo " \033[0;32mObjects eliminated!\033[0m"
		

fclean: clean
	@echo " \033[0;31mNow let's deep clean.\033[0m"
	@echo " \033[0;32mDone.\033[0m"

		

re: fclean all

run: #requires creation of ISO to run
	qemu-system-i386 -cdrom $(ISO) -cpu host