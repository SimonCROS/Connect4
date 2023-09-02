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

t_pos npos(int x, int y);
bool pos_to_index(t_pos pos, int *index);
bool index_to_pos(int index, t_pos *pos);

#endif
