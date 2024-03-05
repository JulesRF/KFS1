#ifndef PRINT_H
# define PRINT_H

# define VGA_ADDRESS 0xB8000

# define BLACK 0
# define BLUE 1
# define GREEN 2
# define CYAN 3
# define RED 4
# define MAGENTA 5
# define BROWN 6
# define L_GREY 7
# define D_GREY 8
# define L_BLUE 9
# define L_GREEN 10
# define L_CYAN 11
# define L_RED 12
# define L_MAGENTA 13
# define YELLOW 14
# define WHITE 15

unsigned short* terminal_buffer;
unsigned int vga_index;

void clear_screen(void);
void print_string(char* str, unsigned char color);
void print_char(char str, unsigned char color);

#endif