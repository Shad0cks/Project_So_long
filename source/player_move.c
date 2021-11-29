#include "../include/header.h"

int size_open(char *path)
{
	char* line;
    int fd;
    int i;


    line = "";
	i = 0;
    fd = open(path, O_RDONLY);
    while (line)
    {
        line = get_next_line(fd);
		if (line)
			i++;
        free(line);
    }
	close(fd);
    return (i);
}

char **put_buffer(char *path)
{
    char  *line;
    int fd;
    int i;
    char **buffer;

    i = 0;
    buffer = malloc(sizeof(char *) * (size_open(path) + 1));
    if (!buffer)
        return (NULL);
    fd = open(path, O_RDONLY);
    line = "";
    while (line)
    {
        line = get_next_line(fd);
        buffer[i] = line;
		i++;
    }
    close(fd);
    return (buffer);
}

void cond1(mlx_t *mlx_st, int x , int y)
{
	if (mlx_st->map_b[y][x] == 'C')
		mlx_st->count_item--;
	else if (mlx_st->map_b[y][x] == 'E' && mlx_st->count_item == 0)
	{
		mlx_st->player->count_move++;
		mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
		mlx_st->player->want_exit = 1;
	}
}

void cond2(mlx_t *mlx_st, int x , int y)
{
	if (mlx_st->map_b[y][x] == 'N')
	{
		mlx_st->player->count_move++;
		mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
		mlx_st->player->will_die = 1;
		refresh_map(mlx_st);
	}
	else if(mlx_st->map_b[y][x] != 'E')
	{
		mlx_st->player->count_move++;
		mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
		mlx_st->map_b[y][x] = 'P';
	}
}

int go_up(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] && 
			mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] != '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y - 1);
		cond2(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y - 1);

	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
    return (1);
}

int go_down(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] && 
			mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] != '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y + 1);
		cond2(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y + 1);
	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
    return (1);
}

int go_left(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] && 
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] != '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x - 1, mlx_st->player->pos_y);
		cond2(mlx_st, mlx_st->player->pos_x - 1, mlx_st->player->pos_y);
	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
    return (1);
}

int go_right(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] &&
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] != '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x + 1, mlx_st->player->pos_y);
		cond2(mlx_st, mlx_st->player->pos_x + 1, mlx_st->player->pos_y);
	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
    return (1);
}