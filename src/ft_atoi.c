#include "connect4.h"

int ft_atoi_full_read(int *result)
{
    int ret;
    int res;
    char c;

    ret = 0;
    while ((res = read(0, &c, 1)) > 0 && c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
        if (ret < 0)
            break;
    }
    *result = ret;
    if (res != 0 && (!c || c == '\n'))
        return 1; // ok

    while (res > 0 && c != '\n') // clean buffer
        res = read(0, &c, 1);

    return res > 0 ? 0 : -1; // 0 if not valid int, -1 if EOF or read error
}

int ft_atoi_full(char const *str, int *result)
{
    int ret;

    ret = 0;
    while (*str >= '0' && *str <= '9')
    {
        ret = ret * 10 + (*str - '0');
        if (ret < 0)
            return (0);
        str++;
    }
    *result = ret;
    return (!(*str));
}
