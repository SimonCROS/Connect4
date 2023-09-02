#include "connect4.h"

extern t_connect4 g_infos;

bool    check_vertical(int player, int pos)
{
    int counter = 1;

    for (int new_pos = pos; move(new_pos, dir_s, &new_pos) && g_infos.board[new_pos] == player;)
        counter++;
    return counter >= 4;
}

bool    check_horizontal(int player, int pos)
{
    int counter = 1;

    for (int new_pos = pos; move(new_pos, dir_e, &new_pos) && g_infos.board[new_pos] == player;)
        counter++;
    for (int new_pos = pos; move(new_pos, dir_w, &new_pos) && g_infos.board[new_pos] == player;)
        counter++;
    return counter >= 4;
}

bool    check_diag_sw_ne(int player, int pos)
{
    int counter = 1;

    for (int new_pos = pos; move(new_pos, dir_sw, &new_pos) && g_infos.board[new_pos] == player;)
        counter++;
    for (int new_pos = pos; move(new_pos, dir_ne, &new_pos) && g_infos.board[new_pos] == player;)
        counter++;
    return counter >= 4;
}

bool    check_diag_nw_se(int player, int pos)
{
    int counter = 1;

    for (int new_pos = pos; move(new_pos, dir_nw, &new_pos) && g_infos.board[new_pos] == player;)
        counter++;
    for (int new_pos = pos; move(new_pos, dir_se, &new_pos) && g_infos.board[new_pos] == player;)
        counter++;
    return counter >= 4;
}