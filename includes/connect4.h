#ifndef CONNECT4_H
# define CONNECT4_H

# include <unistd.h>
# include <stdlib.h>

typedef struct
{
    unsigned char   *board;
    size_t          size_x;
    size_t          size_y;
    size_t          len;
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
    dir_ne = dir_n & dir_e,
    dir_se = dir_s & dir_e,
    dir_sw = dir_s & dir_w,
    dir_nw = dir_n & dir_w,
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

bool check_vertical(int player, int pos);
bool check_horizontal(int player, int pos);
bool check_diag_sw_ne(int player, int pos);
bool check_diag_nw_se(int player, int pos);

#endif
