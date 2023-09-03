#include "connect4.h"

extern t_connect4 g_infos;

int check_highest_in_direction(char player, int index, t_direction direction, int *available)
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

int check_highest_line(char player, int index, t_direction d1, t_direction d2)
{
    int available = 1;
    int counter = 1;

    counter += check_highest_in_direction(player, index, d1, &available);
    counter += check_highest_in_direction(player, index, d2, &available);
    return available >= 4 ? counter : 0;
}

int check_highest_at(char player, int index)
{
    int highest = 0;
    int current = 0;

    current = check_highest_line(player, index, DIR_N, DIR_S);
    highest = current > highest ? current : highest;
    current = check_highest_line(player, index, DIR_E, DIR_W);
    highest = current > highest ? current : highest;
    current = check_highest_line(player, index, DIR_SW, DIR_NE);
    highest = current > highest ? current : highest;
    current = check_highest_line(player, index, DIR_NW, DIR_SE);
    highest = current > highest ? current : highest;

    return highest;
}

void get_highest_in_col(int token, int col, int *highest_val, int *highest_col, int *highest_index)
{
    int index = bottom_index_of_column(col);
    if (index >= 0)
    {
        int value = check_highest_at(token, index);
        if (value > *highest_val)
        {
            *highest_val = value;
            *highest_col = col;
            *highest_index = index;
        }
    }
}

bool get_best_col(int token, int *highest_val, int *highest_col, int *highest_index)
{
    int right = g_infos.cols / 2 + g_infos.cols % 2;
    int left = right - 1;
    while (left >= 0)
    {
        get_highest_in_col(token, left, highest_val, highest_col, highest_index);
        if (right < g_infos.cols)
            get_highest_in_col(token, right, highest_val, highest_col, highest_index);
        left--;
        right++;
    }

    return highest_col >= 0;
}

int ai_turn(int token, int player_token)
{
    print_board();
    ft_putendl("\33[2K\r");

    int highest_player_val = -1;
    int highest_player_col = -1;
    int highest_player_index = -1;
    if (!get_best_col(player_token, &highest_player_val, &highest_player_col, &highest_player_index)) // should never happen
        return -2;

    int highest_ai_val = -1;
    int highest_ai_col = -1;
    int highest_ai_index = -1;
    if (!get_best_col(token, &highest_ai_val, &highest_ai_col, &highest_ai_index)) // should never happen
        return -2;

    if (highest_ai_val == 4)
        return highest_ai_index;

    if (highest_player_val > 2)
        return highest_player_index;

    return highest_ai_index;
}
