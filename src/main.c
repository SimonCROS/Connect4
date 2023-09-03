#include "connect4.h"

t_connect4 g_infos;

void print_status(char *message)
{
    ft_putstr("\33[2K\r");
    ft_putendl(message);
    ft_putstr("\033[8A");
}

void game()
{
    int player = rand() % 2 == 0 ? PLAYER1 : PLAYER2;
    int ret;
    int turn = 0;
    while (true)
    {
        int column;

        print_board();
        ft_putstr("\33[2K\rEnter a column id: ");
        ret = ft_atoi_full_read(&column);
        
        if (ret == -1)
        {
            break;
        }
        else if (ret == 0)
        {
            print_status("\033[31;1mError: invalid number\033[0m");
            continue;
        }
        else
        {
            int index = bottom_index_of_column(column - 1);
            if (index == COLUMN_UNKNOWN)
            {
                print_status("\033[31;1mError: invalid column\033[0m");
                continue;
            }
            if (index == COLUMN_FULL)
            {
                print_status("\033[31mError: column is full\033[0m");
                continue;
            }

            g_infos.board[index] = player;

            if (check_win(player, index))
            {
                print_status("\033[32mGame finished, one winner, one looser, GG everyone.\033[0m");
                print_board();
                ft_putstr("\n\n");
                return;
            }
            if (turn == g_infos.len - 1)
            {
                print_status("\033[32mGame finished, no winner, no looser, GG everyone.\033[0m");
                print_board();
                ft_putstr("\n\n");
                return;
            }
        }

        if (player == PLAYER1)
            player = PLAYER2;
        else
            player = PLAYER1;

        turn++;
        print_status("\33[2K\r");
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
