#include "connect4.h"

extern t_connect4 g_infos;

int player_turn(int token)
{
    int column;
    int ret;

    print_board();
    ft_putstr("\33[2K\rEnter a column id: ");

    ret = ft_atoi_full_read(&column);
    if (ret == -1)
        return -2;
    
    if (ret == 0)
    {
        print_status("\033[31;1mError: invalid number\033[0m");
        return -1;
    }

    int index = bottom_index_of_column(column - 1);
    if (index == COLUMN_UNKNOWN)
    {
        print_status("\033[31;1mError: invalid column\033[0m");
        return -1;
    }
    if (index == COLUMN_FULL)
    {
        print_status("\033[31mError: column is full\033[0m");
        return -1;
    }

    return index;
}
