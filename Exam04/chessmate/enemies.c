#include "chessmate.h"

int pawn(char *board, int width, int i)
{
    if ((board[i - width - 1] == 'K') || (board[i - width + 1] == 'K'))
        return (1);
    return (0);
}

int bishop(char *board, int width, int i)
{
    if ((board[i - width - 1] == 'K') || (board[i - width + 1] == 'K'))
        return (1);
    else if ((board[i - width - 2] == 'K') || (board[i - width + 2] == 'K'))
        return (1);
    else if ((board[i - width - 3] == 'K') || (board[i - width + 3] == 'K'))
        return (1);
    else if ((board[i + width - 1] == 'K') || (board[i + width + 1] == 'K'))
        return (1);
    else if ((board[i + width - 2] == 'K') || (board[i + width + 2] == 'K'))
        return (1);
    else if ((board[i + width - 3] == 'K') || (board[i + width + 3] == 'K'))
        return (1);
    return (0);
}

int rook(char *board, int width, int i)
{
    int j = 1;

    while (j <= 3)
    {
        if ((board[i + width * j] == 'K'))
            return (1);
        j++;
    }
    j = 1;
    while (j <= 3)
    {
        if ((board[i - width * j] == 'K'))
            return (1);
        i++;
    }
    j = 1;
    while (j <= 3)
    {
        if ((board[i + j] == 'K'))
            return (1);
        j++;
    }
    j = 1;
    while (j <= 3)
    {
        if ((board[i - j] == 'K'))
            return (1);
        j++;
    }
    return (0);
}

int queen(char *board, int width, int i)
{
    if (bishop(board, width, i) == 1)
        return (1);
    if (rook(board, width, i) == 1)
        return (1);
    return (0);
}

void enemies(char *board)
{
    int width = ft_strlenln(board);
    int i = 0;
    int success = 0;
    while (board[i])
    {
        if (board[i] == 'P')
        {
            if (pawn(board, width, i) == 1)
            {
                success = 1;
                ft_putstr("Success\n");
            }
        }
        else if (board[i] == 'B')
        {
            if (bishop(board, width, i) == 1)
            {
                success = 1;
                ft_putstr("Success\n");
            }
        }
        else if (board[i] == 'R')
        {
            if (bishop(board, width, i) == 1)
            {
                success = 1;
                ft_putstr("Success\n");
            }
        }
        else if (board[i] == 'Q')
        {
            if (bishop(board, width, i) == 1)
            {
                success = 1;
                ft_putstr("Success\n");
            }
        }
        i++;
    }
    if (success == 0)
        ft_putstr("Fail\n");
}