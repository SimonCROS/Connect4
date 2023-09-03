#include "connect4.h"

extern t_connect4 g_infos;

int count_in_direction(char player, int index, t_direction direction)
{
    int counter = 0;
    int new_index = index;
    while (move(new_index, direction, &new_index))
    {
        if (g_infos.board[new_index] != player)
            break;
        counter++;
    }

    return counter;
}

bool check_vertical(char player, int index)
{
    int counter = 1;
    
    counter += count_in_direction(player, index, DIR_N);
    counter += count_in_direction(player, index, DIR_S);
    return counter >= 4;
}

bool check_horizontal(char player, int index)
{
    int counter = 1;

    counter += count_in_direction(player, index, DIR_E);
    counter += count_in_direction(player, index, DIR_W);
    return counter >= 4;
}

bool check_diag_sw_ne(char player, int index)
{
    int counter = 1;

    counter += count_in_direction(player, index, DIR_SW);
    counter += count_in_direction(player, index, DIR_NE);
    return counter >= 4;
}

bool check_diag_nw_se(char player, int index)
{
    int counter = 1;

    counter += count_in_direction(player, index, DIR_NW);
    counter += count_in_direction(player, index, DIR_SE);
    return counter >= 4;
}

bool check_win(char player, int index)
{
    return check_vertical(player, index)
        || check_horizontal(player, index)
        || check_diag_sw_ne(player, index)
        || check_diag_nw_se(player, index);
}
