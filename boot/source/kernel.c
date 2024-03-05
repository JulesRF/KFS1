#include "kernel.h"
#include "print.h"

int	main(void)
{
	terminal_buffer = (unsigned short*)VGA_ADDRESS;
	vga_index = 0;

	clear_screen();
	print_string("Hello world!", YELLOW);
    vga_index = 80;
    print_string("Version 1", RED);
    vga_index = 160;
    print_char('4', RED);
    print_char('2', YELLOW);
    vga_index = 240;

    while(1);
    return 0 ;
}
