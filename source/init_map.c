#include "../include/header.h"

int strcount(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}
int valid_map()
{
    char* line;
    int fd;
    int count;

    line = "";
    count = 0;
    fd = open("/Users/pierre-louis/Documents/C/Project_So_long/map.ber", O_RDONLY);
    while (line)
    {
        line = get_next_line(fd);
        if(line)
            count++;
        free(line);
    }
    return (count);
}

int calc_map_size(map_t *map)
{
    char* line;
    int fd;
    int count;

    line = "";
    count = 0;
    fd = open("/Users/pierre-louis/Documents/C/Project_So_long/map.ber", O_RDONLY);
    while (line)
    {
        line = get_next_line(fd);
        if (line && strcount(line) != map->max_x && map->max_x != -1)
            return (-1);
        if (map->max_x == -1)
            map->max_x = strcount(line);
        free(line);
        count++;
    }
    map->max_y = count - 1;
    if (map->max_x == map->max_y)
        return (-1);
    return (0);
}

static int check_full_wall(char* str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0' && str[i] != '\n')
    {
        if (str[i] != '1')
            return (-1);
        i++;
    }
    return (0);
}

int check_close(map_t *map)
{
    char* line;
    int fd;
    int count;

    line = "";
    count = 0;
    fd = open("/Users/pierre-louis/Documents/C/Project_So_long/map.ber", O_RDONLY);
    while (line)
    {
        count++;
        line = get_next_line(fd);
        if (count == 1 || count == map->max_y)
            if (check_full_wall(line) == -1)
                return (-1);
        if (line && (line[0] != '1' || line[map->max_x - 1] != '1'))
            return (-1);
        free(line);
    }
    return (0);
}