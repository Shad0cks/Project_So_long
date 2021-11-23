#include "../include/header.h"

void save_sprite(mlx_t *mlx_st, char c, void *sprite)
{
    if (c == 'P')
        mlx_st->player->player_sprite = sprite;
    else if(c == 'C')
    {

    }
}

void *put_image(mlx_t mlx_st, char *imgPath, int x, int y)
{
    void	*img;
    int width = 40;
    int height = 40;

    width = 40;
    height = 40;
    img = mlx_xpm_file_to_image(mlx_st.mlx, imgPath, &width, &height);
    if (!img)
    {
        ft_printf("sprite error");
        exit_func(&mlx_st);
    }
    mlx_put_image_to_window(mlx_st.mlx, mlx_st.window, img, x, y);
    return (img);
}

int put_sprite(mlx_t *mlx_st, char c, char* path)
{
    char* line;
    int fd;
    int i;
    int x;
    int y;

    y = 0;
    line = "";
    fd = open("/Users/pierre-louis/Documents/C/Project_So_long/map.ber", O_RDONLY);
    while (line)
    {
        x = 0;
        i = 0;
        line = get_next_line(fd);
        while (line && line[i] != '\0')
        {
            if (line[i] == c || (c == '0' && line[i] != '1'))
                save_sprite(mlx_st, c, put_image(*mlx_st, path, x, y));
            if (c == 'P' && line[i] == 'P')
                ft_printf("player x : %d / y : %d\n", x, y);
            x += 40;
            i++;
        }
        y += 40;
        free(line);
    }
    return (0);
}