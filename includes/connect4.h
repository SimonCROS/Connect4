#ifndef CONNECT4_H
# define CONNECT4_H

# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define COLUMN_UNKNOWN -1
# define COLUMN_FULL -2

typedef struct
{
    unsigned char   *board;
    int             cols;
    int             lines;
    int             len;
}                   t_connect4;

typedef struct
{
    int             x;
    int             y;
}                   t_pos;

typedef enum { false, true } bool;

typedef enum {
    DIR_N = 1 << 0,
    DIR_E = 1 << 1,
    DIR_S = 1 << 2,
    DIR_W = 1 << 3,
    DIR_NE = DIR_N | DIR_E,
    DIR_SE = DIR_S | DIR_E,
    DIR_SW = DIR_S | DIR_W,
    DIR_NW = DIR_N | DIR_W,
} t_direction;

typedef enum {
    EMPTY = 0,
    PLAYER1 = 1 << 1,
    PLAYER2 = 1 << 2,
    SELECTED = 1 << 3,
} t_cell_flags;

int ft_atoi_full_read(int *result);
int ft_atoi_full(char const *str, int *result);

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
