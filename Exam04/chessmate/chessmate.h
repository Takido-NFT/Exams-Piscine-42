#ifndef CHESSMATE_H
#define CHESSMATE_H

#include <unistd.h>
#include <stdlib.h>

char    *check_args(int ac, char *av[]);
void    ft_putstr(char *str);
void    *board_sjoin(int ac, char *av[]);
int     ft_strlen(char *str);
int     ft_strlenln(char *str);
void    enemies(char *board);

#endif