#include "connect4.h"

extern t_connect4 g_infos;

int check_higher_in_direction(char player, int index, t_direction direction, int *available)
{
    bool aligned = true;
    int counter = 0;
    int new_index = index;

    while (move(new_index, direction, &new_index))
    {
        if (g_infos.board[new_index] != player)
        {
            if (g_infos.board[new_index] == EMPTY)
                aligned = false;
            else
                break;
        }

        if (aligned)
            counter++;
        (*available)++;
    }

    return counter;
}

int check_higher_line(char player, int index, t_direction d1, t_direction d2)
{
    int available = 1;
    int counter = 1;

    counter += check_higher_in_direction(player, index, d1, &available);
    counter += check_higher_in_direction(player, index, d2, &available);
    return available >= 4 ? counter : 0;
}

int check_higher(char player, int index)
{
    int higher = 0;
    int current = 0;

    current = check_higher_line(player, index, DIR_N, DIR_S);
    higher = current > higher ? current : higher;
    current = check_higher_line(player, index, DIR_E, DIR_W);
    higher = current > higher ? current : higher;
    current = check_higher_line(player, index, DIR_SW, DIR_NE);
    higher = current > higher ? current : higher;
    current = check_higher_line(player, index, DIR_NW, DIR_SE);
    higher = current > higher ? current : higher;

    return higher;
}

int ai_turn(int token, int player_token)
{
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
    print_board();
    ft_putendl("\33[2K\r");

    if (higher_ai_col == -1) // should never happen
        return -1;

    if (higher_ai_val == 4)
        return higher_ai_index;

    if (higher_player_val > 2)
        return higher_player_index;

    return higher_ai_index;
}
