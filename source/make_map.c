#include "../include/header.h"

void save_sprite(mlx_t *mlx_st, char c, void *sprite)
{
    if (c == 'P')
        mlx_st->player->player_sprite = sprite;
    else if(c == 'C')
    {

    }
}

void *put_image(mlx_t *mlx_st, char *imgPath, int x, int y)
{
    void	*img;
    int width = 40;
    int height = 40;

    width = 40;
    height = 40;
    img = mlx_xpm_file_to_image(mlx_st->mlx, imgPath, &width, &height);
    if (!img)
    {
        ft_printf("sprite error");
        exit_func(&mlx_st);
    }
    mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, img, x, y);
	mlx_destroy_image(mlx_st->mlx, img);
    return (NULL);
}

int put_sprite(mlx_t *mlx_st, char c, char* path, char **buffer)
{
	int x_b;
	int y_b;
    int x;
    int y;

    y = 0;
	y_b = 0;
	if(c == 'C')
		mlx_st->count_item = 0;
    while (buffer[y_b] != NULL)
    {
        x = 0;
        x_b = 0;

        while (buffer[y_b][x_b] != '\0')
        {
            if (buffer[y_b][x_b] == c || (c == '0' && buffer[y_b][x_b] != '1'))
                save_sprite(mlx_st, c, put_image(mlx_st, path, x, y));
            if (c == 'P' && buffer[y_b][x_b] == 'P')
			{
				mlx_st->player->pos_x = x_b;
				mlx_st->player->pos_y = y_b;
			}
			if (c == 'C' && buffer[y_b][x_b] == 'C')
				mlx_st->count_item += 1;
            x += 40;
            x_b++;
        }
		y_b++;
        y += 40;
    }
    return (0);
}