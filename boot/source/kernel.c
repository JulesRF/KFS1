#include "include/kfs.h"

int	main(void)
{
	screen = 0;
	terminal_buffer[screen] = (unsigned short*)VGA_ADDRESS;
	vga_index[screen] = 0;

	clear_screen();
	clear_screen();
	clear_screen();

	print_string("Hello\n", L_MAGENTA);
    print_string("World", L_CYAN);
    print_string("!", GREEN);
    // vga_index = 160;
    print_char('4', RED);
    print_char('2', YELLOW);
    print_char('0' + ft_strlen("salut"), RED);
    print_string("\n", WHITE);
    // vga_index = 240;

    // shell_ter();

    print_string("Installing interrupt service routines (ISRs).\n", WHITE);
    isr_install();

    print_string("Enabling external interrupts.\n", WHITE);
    asm volatile("sti");

    print_string("Initializing keyboard (IRQ1).\n", WHITE);
    init_keyboard();
    return 0 ;
}


 //le 0 dans print_string sert à sélectionner le terminal sur lequel afficher
 //pourrait être simplié en regardant directement une variable globale à 0 ou 1 selon le screen
 //on pourrait donc ne pas avoir besoin de faire passer en paramètres