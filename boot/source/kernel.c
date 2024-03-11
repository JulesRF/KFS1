#include "include/kfs.h"

int	main(void)
{
	terminal_buffer = (unsigned short*)VGA_ADDRESS;
	vga_index = 0;

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
    // vga_index = 240;

    shell_ter();
    return 0 ;
}
