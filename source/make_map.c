#include "../include/header.h"

void *put_image(mlx_t *mlx_st, void *img, int x, int y)
{
    int width;
    int height ;

    width = 64;
    height = 64;
    if (!img)
    {
        ft_printf("sprite error");
        exit_func(&mlx_st);
    }
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, img, x, y);
    return (NULL);
}

void event_map(int y_b, int x_b, char c, mlx_t *mlx_st)
{
	if (c == 'P' && mlx_st->map_b[y_b][x_b] == 'P')
	{
		mlx_st->player->pos_x = x_b;
		mlx_st->player->pos_y = y_b;
	}
	if (c == 'C' && mlx_st->map_b[y_b][x_b] == 'C')
		mlx_st->count_item += 1;
}

void put_sprite(mlx_t *mlx_st, char c, void* img)
{
	int x_b;
	int y_b;

	y_b = 0;
	if(c == 'C')
		mlx_st->count_item = 0;
    while (mlx_st->map_b[y_b] != NULL)
    {
        x_b = 0;
        while (mlx_st->map_b[y_b][x_b] != '\0')
        {
            if (mlx_st->map_b[y_b][x_b] == c || (c == '0' && mlx_st->map_b[y_b][x_b] != '1'))
            {
                if (c == 'N')
                    put_image(mlx_st, img, x_b * 64 + 10, y_b * 64 + 64);
                else 
                    put_image(mlx_st, img, x_b * 64, y_b * 64 + 64);
            }
            event_map(y_b, x_b, c, mlx_st);
            x_b++;
        }
		y_b++;
    }
}