// int main(void) 
// {
//     for(;;);
// }

#define VGA_ADDRESS 0xB8000

#define BLACK 0
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE_COLOR 15

unsigned short* terminal_buffer;
unsigned int vga_index;

void clear_screen(void)
{
    int index = 0;
    /* there are 25 lines each of 80 columns;
       each element takes 2 bytes */
    while (index < 80 * 25 * 2) {
        terminal_buffer[index] = ' ';
        index += 2;
    }
}

void print_string(char* str, unsigned char color)
{
    int index = 0;
    while (str[index]) {
        terminal_buffer[vga_index] = (unsigned short)str[index] | (unsigned short)color << 8;
        index++;
        vga_index++;
    }
}

void print_char(char str, unsigned char color)
{
    int index = 0;
    
    terminal_buffer[vga_index] = str | (unsigned short)color << 8;
    index++;
    vga_index++;
    
}

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
