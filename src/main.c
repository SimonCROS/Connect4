#include "connect4.h"

t_connect4 g_infos;

bool    win(int player, int pos)
{
    return check_vertical(player, pos)
        || check_horizontal(player, pos)
        || check_diag_sw_ne(player, pos)
        || check_diag_nw_se(player, pos);
}

/// @brief Get the neighbor cell of pos
/// @param index the start position
/// @param dir the direction in which the next cell will be searched
/// @param res the result of the move
/// @return true if a result was found, false otherwise
bool    move(int index, t_direction dir, int *res)
{
    t_pos pos;
    index_to_pos(index, &pos);

    if (dir & dir_n)
        pos.y--;
    if (dir & dir_e)
        pos.x++;
    if (dir & dir_s)
        pos.y++;
    if (dir & dir_w)
        pos.x--;

    return pos_to_index(pos, res);
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    g_infos.size_x = 7;
    g_infos.size_y = 6;
    g_infos.len = g_infos.size_x * g_infos.size_y;

    srand(time(NULL));
    int player = rand() % 2;

    if (!(g_infos.board = malloc(g_infos.len)))
        return 0;

    for (size_t i = 0; i < g_infos.len; i++)
        g_infos.board[i] = '-';

    print_board();
    
    int read;
    int ret;
    while ((ret = ft_atoi_full_read(&read)) != -1)
    {
        if (ret == 0)
            ft_putendl_fd("Error: invalid number", 2);
        else
            printf("`%d`\n", read);
    }

    free(g_infos.board);
    return 0;
}
