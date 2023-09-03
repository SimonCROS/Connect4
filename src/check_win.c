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

bool check_line(char player, int index, t_direction d1, t_direction d2)
{
    int counter = 1;

    counter += check_in_direction(player, index, d1);
    counter += check_in_direction(player, index, d2);
    return counter >= 4;
}

bool check_win(char player, int index)
{
    if (check_line(player, index, DIR_N, DIR_S))
        return true;
    reset_selection();
    if (check_line(player, index, DIR_E, DIR_W))
        return true;
    reset_selection();
    if (check_line(player, index, DIR_SW, DIR_NE))
        return true;
    reset_selection();
    if (check_line(player, index, DIR_NW, DIR_SE))
        return true;
    reset_selection();
    return false;
}
