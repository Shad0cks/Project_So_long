#include "../include/header.h"

int check_piece_here(char c)
{
    char* line;
    int fd;
    int piece;

    line = "";
    piece = 0;
    fd = open("/Users/pierre-louis/Documents/C/Project_So_long/map.ber", O_RDONLY);
    while (line)
    {
        line = get_next_line(fd);
        if(line)
            if(ft_strchr(line, c))
                return (1);
        free(line);
    }
    return (0);
}