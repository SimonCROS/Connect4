#include "connect4.h"

extern t_connect4 g_infos;

t_pos npos(int x, int y)
{
    return (t_pos){x, y};
}

bool pos_to_index(t_pos pos, int *index)
{
    if (pos.x < 0 || pos.x >= g_infos.size_x)
        return false;
    if (pos.y < 0 || pos.y >= g_infos.size_y)
        return false;
    *index = pos.y * g_infos.size_x + pos.x;
    return true;
}

bool index_to_pos(int index, t_pos *pos)
{
    *pos = npos(index % g_infos.size_x, index / g_infos.size_x);
    return index >= 0 && index < g_infos.len;
}

void print_board()
{
    for (size_t y = 0; y < g_infos.size_y; y++)
    {
        write(0, "|", 1);
        write(0, g_infos.board + (y * g_infos.size_x), g_infos.size_x);
        write(0, "|\n", 2);
    }
}
