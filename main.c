#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char *str;

    int fd = open("get_next_line.c", O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        printf("%s",str);
        free(str);
    }
}