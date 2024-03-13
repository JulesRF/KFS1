#include "include/kfs.h"

int	main(void)
{
	screen = 1;
	terminal_buffer[0] = (unsigned short*)VGA_ADDRESS;
	vga_index[1] = 0;
	vga_index[2] = 0;

	clear_screen(0);
	clear_screen(0);
	clear_screen(0);

	print_string("Hello\n", L_MAGENTA);
    print_string("World", L_CYAN);
    print_string("!", GREEN);
    // vga_index = 160;
    print_char('4', RED);
    print_char('2', YELLOW);
	ft_putnbr_hex(42, WHITE);
	ft_putnbr(42, WHITE);
    print_char('0' + ft_strlen("salut"), RED);
    print_string("\n", WHITE);
	// ft_switch_screen();
	// ft_switch_screen();
    // vga_index = 240;

    shell_ter();
    return 0 ;
}


 //le 0 dans print_string sert à sélectionner le terminal sur lequel afficher
 //pourrait être simplié en regardant directement une variable globale à 0 ou 1 selon le screen
 //on pourrait donc ne pas avoir besoin de faire passer en paramètres