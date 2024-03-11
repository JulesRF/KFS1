#include "include/kfs.h"

unsigned short *terminal_buffer;
unsigned int    vga_index;

void clear_screen(void)
{
    int index = 0;
    /* there are 25 lines each of 80 columns;
       each element takes 2 bytes */
    while (index < 80 * 25 * 2) {
        terminal_buffer[index] = ' ';
        index += 1; //TODO modified from 2, was not working with the make kernel
    }
}

void print_string(char* str, unsigned char color)
{
    int index = 0;
    while (str[index]) {
        ft_isnewl(str, index);
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

int ft_isnewl(const char *str, int i)
{
    if (str[i] == '\n')
    {
        vga_index = vga_index + 80 - (vga_index % 80) - 1;
        return (1);
    }
    return (0);
}

void    ft_printerr(char *str)
{
    print_string(str, RED);
}