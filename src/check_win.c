#include "connect4.h"

extern t_connect4 g_infos;

int check_in_direction(char player, int index, t_direction direction)
{
    int counter = 0;
    int new_index = index;

    g_infos.board[new_index] |= SELECTED;
    while (move(new_index, direction, &new_index))
    {
        if (g_infos.board[new_index] != player)
            break;
        counter++;
        g_infos.board[new_index] |= SELECTED;
    }

    return counter;
}

void reset_selection()
{
    for (int i = 0; i < g_infos.len; i++)
        g_infos.board[i] &= ~SELECTED;
}

bool check_vertical(char player, int index)
{
    int counter = 1;
    
    counter += check_in_direction(player, index, DIR_N);
    counter += check_in_direction(player, index, DIR_S);
    return counter >= 4;
}

bool check_horizontal(char player, int index)
{
    int counter = 1;

    counter += check_in_direction(player, index, DIR_E);
    counter += check_in_direction(player, index, DIR_W);
    return counter >= 4;
}

bool check_diag_sw_ne(char player, int index)
{
    int counter = 1;

    counter += check_in_direction(player, index, DIR_SW);
    counter += check_in_direction(player, index, DIR_NE);
    return counter >= 4;
}

bool check_diag_nw_se(char player, int index)
{
    int counter = 1;

    counter += check_in_direction(player, index, DIR_NW);
    counter += check_in_direction(player, index, DIR_SE);
    return counter >= 4;
}

bool check_win(char player, int index)
{
    if (check_vertical(player, index))
        return true;
    reset_selection();
    if (check_horizontal(player, index))
        return true;
    reset_selection();
    if (check_diag_sw_ne(player, index))
        return true;
    reset_selection();
    if (check_diag_nw_se(player, index))
        return true;
    reset_selection();
    return false;
}
