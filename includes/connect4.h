#ifndef CONNECT4_H
# define CONNECT4_H

# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define EMPTY '-'
# define PLAYER1 'o'
# define PLAYER2 'x'
# define COLUMN_UNKNOWN -1
# define COLUMN_FULL -2

typedef struct
{
    unsigned char   *board;
    int             width;
    int             height;
    int             len;
}                   t_connect4;

typedef struct
{
    int             x;
    int             y;
}                   t_pos;

typedef enum { false, true } bool;

typedef enum {
    dir_n = 1 << 0,
    dir_e = 1 << 1,
    dir_s = 1 << 2,
    dir_w = 1 << 3,
    dir_ne = dir_n | dir_e,
    dir_se = dir_s | dir_e,
    dir_sw = dir_s | dir_w,
    dir_nw = dir_n | dir_w,
} t_direction;

int ft_atoi_full_read(int *result);

size_t ft_strlen(const char *s);
ssize_t ft_putstr(char *s);
ssize_t	ft_putendl(char *s);
ssize_t	ft_putchar(char c);
ssize_t ft_putstr_fd(char *s, int fd);
ssize_t	ft_putendl_fd(char *s, int fd);
ssize_t	ft_putchar_fd(char c, int fd);

t_pos npos(int x, int y);
bool pos_to_index(t_pos pos, int *index);
bool index_to_pos(int index, t_pos *pos);

bool check_win(char player, int pos);
bool check_vertical(char player, int pos);
bool check_horizontal(char player, int pos);
bool check_diag_sw_ne(char player, int pos);
bool check_diag_nw_se(char player, int pos);

bool move(int index, t_direction dir, int *res);
int bottom_index_of_column(int x);
void print_board();

#endif
