#include "include/kfs.h"

unsigned short *terminal_buffer[3];
unsigned int    vga_index[3];
unsigned int	screen;

void	clear_screen(int screen)
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

void	ft_switch_screen()
{
	int index = 0;
	int old_screen;

	if (screen == 0)
	{
		screen = 1;
		old_screen = 0;
	}
	else if (screen == 1)
	{
		screen = 0;
		old_screen = 1;
	}
	clear_screen(0);
	while (index < 80 * 25 * 2)
	{
		terminal_buffer[0][index] = terminal_buffer[old_screen][index];
		index++;
	}
}

void	print_string(char* str, unsigned char color)
{
    int index = 0;
    while (str[index])
    {
        ft_isnewl(str, index);
		if (str[index] != '\n')
		{
	        terminal_buffer[screen][vga_index[screen]] = (unsigned short)str[index] | (unsigned short)color << 8;
			terminal_buffer[0][vga_index[screen]] = (unsigned short)str[index] | (unsigned short)color << 8;
		}	
        index++;
        vga_index[screen]++;
    }
}

void	print_char(char str, unsigned char color)
{
    int index = 0;
    
    terminal_buffer[screen][vga_index[screen]] = str | (unsigned short)color << 8;
	terminal_buffer[0][vga_index[screen]] = str | (unsigned short)color << 8;

    index++;
    vga_index[screen]++;
}

int	ft_isnewl(const char *str, int i)
{
    if (str[i] == '\n')
    {
        vga_index[screen] = vga_index[screen] + 80 - (vga_index[screen] % 80) - 1;
        return (1);
    }
    return (0);
}

void	ft_putnbr_hex(int nbr, unsigned char color)
{
	char	base[16] = "0123456789ABCDEF";
	int		size = 16;

	if (nbr < 0)
	{
		print_char('-', color);
		nbr = nbr * -1;
	}
	if (nbr <= size)
		print_char(base[nbr % size], color);
	else
	{
		ft_putnbr_hex(nbr / size, color);
		print_char(base[nbr % size], color);
	}
}

void	ft_putnbr(int nbr, unsigned char color)
{
	if (nbr < 0)
	{
		print_char('-', WHITE);
		nbr = nbr * -1;
	}
	if (nbr <= 9)
		print_char(nbr + '0', color);
	else
	{
		ft_putnbr(nbr / 10, color);
		print_char(nbr % 10 + '0', color);
	}
}

void    ft_printerr(char *str)
{
    print_string(str, RED);
}