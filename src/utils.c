#include "connect4.h"

extern t_connect4 g_infos;

/// @brief Get the neighbor cell of pos
/// @param index the start position
/// @param dir the direction in which the next cell will be searched
/// @param res the result of the move
/// @return true if a result was found, false otherwise
bool move(int index, t_direction dir, int *res)
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

/// @brief Returns the lowest cell avaliable in the column
/// @param x the index of the column
/// @return the index of the lowest cell avaliable or -1 if column is full
int bottom_index_of_column(int x)
{
    for (int y = 0; y < g_infos.lines; y++)
    {
        int index;
        if (!pos_to_index(npos(x, y), &index))
            return COLUMN_UNKNOWN;
        if (g_infos.board[index] == EMPTY)
            return index;
    }
    return COLUMN_FULL;
}

t_pos npos(int x, int y)
{
    return (t_pos){x, y};
}

bool pos_to_index(t_pos pos, int *index)
{
    if (pos.x < 0 || pos.x >= g_infos.cols)
        return false;
    if (pos.y < 0 || pos.y >= g_infos.lines)
        return false;
    *index = pos.y * g_infos.cols + pos.x;
    return true;
}

bool index_to_pos(int index, t_pos *pos)
{
    *pos = npos(index % g_infos.cols, index / g_infos.cols);
    return index >= 0 && index < g_infos.len;
}

void print_board()
{
    for (int y = g_infos.lines - 1; y >= 0; y--)
    {
        write(0, "|", 1);
        write(0, g_infos.board + (y * g_infos.cols), g_infos.cols);
        write(0, "|\n", 2);
    }
}
