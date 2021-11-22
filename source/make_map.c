#include "../include/header.h"

void put_image(mlx_t mlx_st, char *imgPath, int x, int y)
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
}

int put_sprite(mlx_t mlx_st, char c, char* path)
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
                put_image(mlx_st, path, x, y);
            x += 40;
            i++;
        }
        y += 40;
        free(line);
    }
    return (0);
}