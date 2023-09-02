#include "connect4.h"

t_connect4 g_infos;

void game()
{
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
                return;
            }
            if (turn == g_infos.len - 1)
            {
                ft_putendl_fd("\033[32mGame finished, no winner, no looser, GG everyone.\033[0m", 2);
                print_board();
                return;
            }
        }

        player = !player;
        turn++;
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    if (argc != 3)
    {
        ft_putendl_fd("Usage: ./connect4 lines columns", 2);
        return 1;
    }
    if (!ft_atoi_full(argv[1], &g_infos.lines) || !ft_atoi_full(argv[2], &g_infos.cols))
    {
        ft_putendl_fd("lines and columns must be valid numbers", 2);
        return 1;
    }
    if (g_infos.lines < 6 || g_infos.lines > 50)
    {
        ft_putendl_fd("lines must be in range 6-50 (inclusive)", 2);
        return 1;
    }
    if (g_infos.cols < 7 || g_infos.cols > 50)
    {
        ft_putendl_fd("columns must be in range 7-50 (inclusive)", 2);
        return 1;
    }

    g_infos.len = g_infos.cols * g_infos.lines;

    if (!(g_infos.board = malloc(g_infos.len)))
        return 0;

    for (int i = 0; i < g_infos.len; i++)
        g_infos.board[i] = EMPTY;
    
    game();

    free(g_infos.board);
    return 0;
}
