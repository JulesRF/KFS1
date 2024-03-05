# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 14:00:09 by rdel-agu          #+#    #+#              #
#    Updated: 2024/03/05 16:05:01 by rdel-agu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kfs

BIN = $(NAME).bin

ISO_DIR = iso

ISO = $(NAME).iso

CC = gcc

LD = ld

NASM = nasm

RM = rm

CFLAGS = -fno-builtin \
		 -fno-exceptions \
		 -fno-stack-protector \
		 -nostdlib \
		 -nodefaultlibs \
		 -Wall \
		 -Werror \
		 -Wextra \
		 -g3 \
		 -m32

CFILES = boot/source/kernel.c \
		 boot/source/print.c

CHEADER = boot/source/print.h
		 
		 
CFG = boot/grub/grub.cfg
BOOT = boot/boot.asm
BOOT_OBJ = boot/boot.o
OBJ = boot/source/kernel.o

.PHONY: all run boot

all: boot $(OBJ) link iso 

boot : $(BOOT_OBJ)
	$(NASM) -f elf32 $(BOOT) -o $(BOOT_OBJ)

%.o: ${CFILES}/%.c
	$(CC) $(CFLAGS) -I $(CHEADER) -c $< -o $@

%.o : %.asm
	$(NASM) -f elf32 -g -F dwarf $< -o $@

link: $(BOOT_OBJ) $(OBJ) 
	$(LD) -m elf_i386 -T boot/linker.ld boot/source/kernel.o -o $(BIN) $(BOOT_OBJ)

iso:
	mkdir -pv $(ISO_DIR)/boot/grub
	cp $(BIN) $(ISO_DIR)/boot/$(BIN)
	cp $(CFG) $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_DIR)

clean:
	@echo " \033[0;31mCleaning objects!\033[30m"
	$(RM) -f $(BOOT_OBJ)
	$(RM) -f $(OBJ)
	@echo " \033[0;32mObjects eliminated!\033[0m"
		
fclean: clean
	@echo " \033[0;31mNow let's deep clean.\033[30m"
	$(RM) -f $(BIN)
	$(RM) -f $(ISO_DIR)/boot/$(BIN)
	$(RM) -f $(ISO_DIR)/boot/grub/$(CFG)
	$(RM) -rf $(ISO_DIR)
	$(RM) -f $(NAME).iso
	@echo " \033[0;32mDone.\033[0m"

re: fclean all

run:
	qemu-system-i386 -cdrom $(ISO)

kernel:
	qemu-system-i386 -kernel $(BIN)