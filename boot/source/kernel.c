#include "include/kfs.h"

int	main(void)
{
	terminal_buffer[0] = (unsigned short*)VGA_ADDRESS;
	vga_index[0] = 0;

	clear_screen(0);
	clear_screen(0);
	clear_screen(0);

	print_string("Hello\n", L_MAGENTA, 0);
    print_string("World", L_CYAN, 0);
    print_string("!", GREEN, 0);
    // vga_index = 160;
    print_char('4', RED, 0);
    print_char('2', YELLOW, 0);
    print_char('0' + ft_strlen("salut"), RED, 0);
    print_string("\n", WHITE, 0);
    // vga_index = 240;

    // shell_ter();

    print_string("Installing interrupt service routines (ISRs).\n", WHITE, 0);
    isr_install();

    print_string("Enabling external interrupts.\n", WHITE, 0);
    asm volatile("sti");

    print_string("Initializing keyboard (IRQ1).\n", WHITE, 0);
    init_keyboard();
    // return 0 ;
}


 //le 0 dans print_string sert à sélectionner le terminal sur lequel afficher
 //pourrait être simplié en regardant directement une variable globale à 0 ou 1 selon le screen
 //on pourrait donc ne pas avoir besoin de faire passer en paramètres