#include "connect4.h"

t_connect4 g_infos;

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    g_infos.width = 7;
    g_infos.height = 6;
    g_infos.len = g_infos.width * g_infos.height;

    if (!(g_infos.board = malloc(g_infos.len)))
        return 0;

    for (int i = 0; i < g_infos.len; i++)
        g_infos.board[i] = EMPTY;
    

    int player = rand() % 2;
    int ret;
    int turn = 0;
    while (true)
    {
        int column;

        print_board();
        ft_putstr("Enter a column id: ");
        ret = ft_atoi_full_read(&column);
        
        if (ret == -1)
        {
            break;
        }
        else if (ret == 0)
        {
            ft_putendl_fd("Error: invalid number", 2);
            continue;
        }
        else
        {
            int index = bottom_index_of_column(column - 1);
            if (index == COLUMN_UNKNOWN)
            {
                ft_putendl_fd("\033[31;1mError: invalid column\033[0m", 2);
                continue;
            }
            if (index == COLUMN_FULL)
            {
                ft_putendl_fd("\033[31mError: column is full\033[0m", 2);
                continue;
            }

            char player_token = player ? PLAYER1 : PLAYER2;
            g_infos.board[index] = player_token;

            if (check_win(player_token, index))
            {
                ft_putendl_fd("\033[32mGame finished, one winner, one looser, GG everyone.\033[0m", 2);
                print_board();
                return 0;
            }
            if (turn == g_infos.len - 1)
            {
                ft_putendl_fd("\033[32mGame finished, no winner, no looser, GG everyone.\033[0m", 2);
                print_board();
                return 0;
            }
        }

        player = !player;
        turn++;
    }

    free(g_infos.board);
    return 0;
}
