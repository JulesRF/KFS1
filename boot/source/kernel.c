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
    ft_printerr("\nError\nSegfault", 0);
    // vga_index = 240;

    shell_ter();
    return 0 ;
}
