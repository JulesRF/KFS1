#include "include/kfs.h"


uint16	*vga_buffer;
uint16	terminal_buffer[2][VGA_ADDRESS];
uint32	terminal_index[2];
uint32	vga_index;
uint32	screen = 0;

void	clear_screen2(int this_screen)
{
	ft_memset(terminal_buffer[this_screen], 0x00, 80 * 25);
	terminal_index[this_screen] = 0;
}

void	clear_screen(int this_screen)
{
	if (this_screen == 100)
	{
		ft_memset(vga_buffer, 0x00, 80 * 25);
		vga_index = 0;
	}
	else
		clear_screen2(this_screen);

}

void	ft_switch_screen()
{
	unsigned int index = 0;
	// int old_screen;

	clear_screen(100);
	if (screen == 0)
		screen = 1;
	else if (screen == 1)
		screen = 0;
	while (index < 80 * 25 * 2)
	{
		// if (terminal_buffer[screen][index] >= 32 && terminal_buffer[screen][index] <= 126)
		vga_buffer[index] = terminal_buffer[screen][index];
		index++;
	}
	vga_index = terminal_index[screen];
	print_status();	
}

void	print_string(char* str, unsigned char color)
{
    int index = 0;
    while (str[index])
    {
        ft_isnewl(str, index);
		if (str[index] == 8)
			ft_backspace();
		else if (str[index] != '\n')
		{
	        terminal_buffer[screen][terminal_index[screen]] = (unsigned short)str[index] | (unsigned short)color << 8;
			vga_buffer[terminal_index[screen]] = terminal_buffer[screen][terminal_index[screen]];
		}
		terminal_index[screen]++;
        index++;
    }
}

void	print_char(char str, unsigned char color)
{
    int index = 0;
    
    terminal_buffer[screen][terminal_index[screen]] = str | (unsigned short)color << 8;
	vga_buffer[terminal_index[screen]] = terminal_buffer[screen][terminal_index[screen]];

    index++;
    terminal_index[screen]++;
}

int	ft_isprompt()
{
	int prompt[8] = {'k', 'f', 's', '-', '1', ' ', '>',};

	for(int i = 0; i < 8; i++)
	{
		if (terminal_buffer[screen][terminal_index[screen] - 8 + i] != prompt[i])
			return (0);
	}
	return (1);
}

void	ft_backspace()
{
	if (ft_isprompt())
		print_string("ASKIP y'a le prompt", WHITE);
	if (terminal_index[screen] % 80 != 0)
	{
		terminal_index[screen]--;
		terminal_buffer[screen][terminal_index[screen]] = ' ';
		vga_buffer[terminal_index[screen]] = terminal_buffer[screen][terminal_index[screen]];
	}
}

int	ft_isnewl(const char *str, int i)
{
    if (str[i] == '\n')
    {
        terminal_index[screen] = terminal_index[screen] + 80 - (terminal_index[screen] % 80) - 1;
        return (1);
    }
    return (0);
}

void	ft_prompt()
{
	int color42 = BROWN;

    print_string("*--------------------*------------------------------------*--------------------*", color42);
    print_string("|     dP88  oP\"Yb.   |    Welcome to KFS-1!               |    SCREEN          |", color42);
    print_string("|    dP 88  \"\' dP\'   |                                    |    CAPS_LOCK       |", color42);
    print_string("|   d888888   dP'    |    Made by jroux-fo && rdel-agu    |    SHIFT           |", color42);
    print_string("|       88  .d8888   |                                    |    CTRL            |", color42);
    print_string("*--------------------*------------------------------------*--------------------*\n", color42);

    print_string("kfs-1 > ", L_BLUE);
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

void    *ft_memset(void *b, int c, uint16 len)
{
    uint16            i;
    unsigned char    *dest;

    i = 0;
    dest = (unsigned char *)b;
    while (i < len)
    {
        dest[i] = (unsigned char)c;
        i++;
    }
    return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (((unsigned char)s1[i] || (unsigned char)s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


void	print_status( void ) {

	vga_buffer[155] = (screen + '1') | WHITE << 8;
	vga_buffer[155 + 80] = (isCapsPressed + '0') | WHITE << 8;
	vga_buffer[155 + 80 * 2] = (isShiftPressed + '0') | WHITE << 8;
	vga_buffer[155 + 80 * 3] = (isCtrlPressed + '0') | WHITE << 8;
}
