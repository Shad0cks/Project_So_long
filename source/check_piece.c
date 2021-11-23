#include "../include/header.h"

int check_piece_here(char c)
{
    char* line;
    int fd;
    int piece;

    line = "";
    piece = 0;
    fd = open("../map.ber", O_RDONLY);
    while (line)
    {
        line = get_next_line(fd);
        if(line)
            if(ft_strchr(line, c))
                return (1);
        free(line);
    }
	close(fd);
    return (0);
}

int check_all_piece()
{
    char* line;
    int fd;
    int i;

    line = "";
    fd = open("../map.ber", O_RDONLY);
    while (line)
    {
        line = get_next_line(fd);
        i = 0;
        while(line && line[i] != '\0')
        {
            if (line[i] != '1' && line[i] != '0' && line[i] != 'P' 
                        && line[i] != 'C' && line[i] != 'E' && line[i] != 10)
                return (0);
            i++;
        }
        free(line);
    }
	close(fd);
    return (1);
}
