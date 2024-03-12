#include "include/kfs.h"

unsigned short *terminal_buffer[2];
unsigned int    vga_index[2];
unsigned int	screen;

void clear_screen()
{
    int index = 0;
    /* there are 25 lines each of 80 columns;
       each element takes 2 bytes */
    while (index < 80 * 25 * 2)
    {
        terminal_buffer[screen][index] = ' ';
        index += 1; //TODO modified from 2, was not working with the make kernel
    }
}

void print_string(char* str, unsigned char color)
{
    int index = 0;
    while (str[index])
    {
        ft_isnewl(str, index);
		if (str[index] != '\n')
	        terminal_buffer[screen][vga_index[screen]] = (unsigned short)str[index] | (unsigned short)color << 8;
        index++;
        vga_index[screen]++;
    }
}

void print_char(char str, unsigned char color)
{
    int index = 0;
    
    terminal_buffer[screen][vga_index[screen]] = str | (unsigned short)color << 8;
    index++;
    vga_index[screen]++;
}

int ft_isnewl(const char *str, int i)
{
    if (str[i] == '\n')
    {
        vga_index[screen] = vga_index[screen] + 80 - (vga_index[screen] % 80) - 1;
        return (1);
    }
    return (0);
}

void    ft_printerr(char *str)
{
    print_string(str, RED);
}