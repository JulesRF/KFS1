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

extern unsigned short	*terminal_buffer[3];
extern unsigned int		vga_index[3];
extern unsigned int		screen;

void    clear_screen(int screen);
void	ft_switch_screen();
void    print_string(char* str, unsigned char color);
void    print_char(char str, unsigned char color);
void	ft_backspace();
int     ft_isnewl(const char *str, int i);
void	ft_putnbr_hex(int nbr, unsigned char color);
void	ft_putnbr(int nbr, unsigned char color);
void    ft_printerr(char *str);
void	ft_ctrl_backspace();

#endif