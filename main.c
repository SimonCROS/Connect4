#include "unistd.h"

int main(int argc, char const *argv[])
{
    write(0, "HEY\n", 4);
    return 0;
}
