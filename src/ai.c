#include "connect4.h"

extern t_connect4 g_infos;


int check_higher_in_direction(char player, int index, t_direction direction)
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

int check_higher_vertical(char player, int index)
{
    int counter = 1;
    
    counter += check_higher_in_direction(player, index, DIR_N);
    counter += check_higher_in_direction(player, index, DIR_S);
    return counter;
}

int check_higher_horizontal(char player, int index)
{
    int counter = 1;

    counter += check_higher_in_direction(player, index, DIR_E);
    counter += check_higher_in_direction(player, index, DIR_W);
    return counter;
}

int check_higher_diag_sw_ne(char player, int index)
{
    int counter = 1;

    counter += check_higher_in_direction(player, index, DIR_SW);
    counter += check_higher_in_direction(player, index, DIR_NE);
    return counter;
}

int check_higher_diag_nw_se(char player, int index)
{
    int counter = 1;

    counter += check_higher_in_direction(player, index, DIR_NW);
    counter += check_higher_in_direction(player, index, DIR_SE);
    return counter;
}

int check_higher(char player, int index)
{
    int higher = 0;
    int current = 0;

    higher = check_higher_vertical(player, index);

    current = check_higher_horizontal(player, index);
    higher = current > higher ? current : higher;
    current = check_higher_diag_sw_ne(player, index);
    higher = current > higher ? current : higher;
    current = check_higher_diag_nw_se(player, index);
    higher = current > higher ? current : higher;

    return higher;
}

int ai_turn(int token, int player_token)
{
    print_board();
    ft_putendl("\33[2K\r");

    int higher_player_val = -1;
    int higher_player_col = -1;
    int higher_player_index = -1;
    for (int x = 0; x < g_infos.cols; x++)
    {
        int index = bottom_index_of_column(x);
        if (index >= 0)
        {
            int value = check_higher(player_token, index);
            if (value > higher_player_val)
            {
                higher_player_val = value;
                higher_player_col = x;
                higher_player_index = index;
            }
        }
    }

    if (higher_player_col == -1) // should never happen
        return -1;

    int higher_ai_val = -1;
    int higher_ai_col = -1;
    int higher_ai_index = -1;
    for (int x = 0; x < g_infos.cols; x++)
    {
        int index = bottom_index_of_column(x);
        if (index >= 0)
        {
            int value = check_higher(token, index);
            if (value > higher_ai_val)
            {
                higher_ai_val = value;
                higher_ai_col = x;
                higher_ai_index = index;
            }
        }
    }

    if (higher_ai_col == -1) // should never happen
        return -1;

    if (higher_ai_val == 4)
        return higher_ai_index;

    if (higher_player_val > 2)
        return higher_player_index;

    return higher_ai_index;
}
