#include "../include/header.h"

int size_open()
{
	char* line;
    int fd;
    int i;


    line = "";
	i = 0;
    fd = open("../map.ber", O_RDONLY);
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

char **put_buffer()
{
    char  *line;
    int fd;
    int i;
    char **buffer;

    i = 0;
    buffer = malloc(sizeof(char *) * (size_open() + 1));
    if (!buffer)
        return (NULL);
    fd = open("../map.ber", O_RDONLY);
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

int go_up(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] && mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] != '1')
	{
		if (mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] == 'C')
			mlx_st->count_item--;
		else if (mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] == 'E' && mlx_st->count_item == 0)
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->want_exit = 1;
		}
		if (mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] == 'N')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->will_die = 1;
			refresh_map(mlx_st);
			put_image(mlx_st, mlx_st->map_sprite->tomb, mlx_st->player->pos_x * 64, mlx_st->player->pos_y * 64 + 64 + 18);

		}
		else if(mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] != 'E')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] = 'P';
		}
	}
	refresh_map(mlx_st);
    return (1);
}

int go_down(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] && mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] != '1')
	{
		if (mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] == 'C')
			mlx_st->count_item--;
		else if (mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] == 'E' && mlx_st->count_item == 0)
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->want_exit = 1;
		}
		if (mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] == 'N')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->will_die = 1;
			refresh_map(mlx_st);
			put_image(mlx_st, mlx_st->map_sprite->tomb, mlx_st->player->pos_x * 64, mlx_st->player->pos_y * 64 + 64 + 18);

		}
		else if(mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] != 'E')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] = 'P';
		}
	}
	refresh_map(mlx_st);
    return (1);
}

int go_left(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] && mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] != '1')
	{
		if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] == 'C')
			mlx_st->count_item--;
		else if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] == 'E' && mlx_st->count_item == 0)
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->want_exit = 1;
		}
		if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] == 'N')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->will_die = 1;
			refresh_map(mlx_st);
			put_image(mlx_st, mlx_st->map_sprite->tomb, mlx_st->player->pos_x * 64, mlx_st->player->pos_y * 64 + 64 + 18);

		}
		else if(mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] != 'E')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] = 'P';
		}
	}
	refresh_map(mlx_st);
    return (1);
}

int go_right(mlx_t *mlx_st)
{
    mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] && mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] != '1')
	{
		if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] == 'C')
			mlx_st->count_item--;
		else if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] == 'E' && mlx_st->count_item == 0)
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->want_exit = 1;
		}
		if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] == 'N')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->player->will_die = 1;
			refresh_map(mlx_st);
			put_image(mlx_st, mlx_st->map_sprite->tomb, mlx_st->player->pos_x * 64, mlx_st->player->pos_y * 64 + 64 + 18);

		}
		else if(mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] != 'E')
		{
			mlx_st->player->count_move++;
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] = 'P';
		}
	}
	refresh_map(mlx_st);
    return (1);
}