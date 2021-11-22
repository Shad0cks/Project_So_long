#include "../include/header.h"

void exit_func(void* params)
{
    mlx_t *mlx_st;
    mlx_st = (mlx_t *)params;
    mlx_destroy_window(mlx_st->mlx, mlx_st->window);
    exit(0);
}
int exit_cross(int keycode, void* params)
{
    (void)keycode;
    (void)params;
    exit(0);
    return (0); 
}
int key_listen(int keycode, void* params)
{
    //ft_printf("keycode : %d\n", keycode);
    if (keycode == 53)
        exit_func(params);
    return (0);
}

int main(void)
{
    map_t map;
    map.max_x = -1;
    map.max_y = -1;
    if(!check_all_piece())
    {
        ft_printf("no valid piece in map");
        exit(-1);
    }
    if (!check_piece_here('P') || !check_piece_here('E') || !check_piece_here('C'))
    {
        ft_printf("map piece error");
        exit(-1);
    }
    if(valid_map() <= 2 || calc_map_size(&map) == -1 || check_close(&map) == -1)
    {
        ft_printf("map error");
        exit(-1);
    }
    mlx_t mlx_st;
    mlx_st.mlx = mlx_init();
    if (mlx_st.mlx == NULL)
        exit(-1);
    mlx_st.window = mlx_new_window(mlx_st.mlx, map.max_x * 40, map.max_y * 40, "So_long");

    //creating image and put it-----------------------
    put_sprite(mlx_st, '0', "/Users/pierre-louis/Documents/C/Project_So_long/sprite/sand.xpm");
    put_sprite(mlx_st, '1', "/Users/pierre-louis/Documents/C/Project_So_long/sprite/wall.xpm");
    put_sprite(mlx_st, 'C', "/Users/pierre-louis/Documents/C/Project_So_long/sprite/item.xpm");
    put_sprite(mlx_st, 'E', "/Users/pierre-louis/Documents/C/Project_So_long/sprite/door.xpm");
    put_sprite(mlx_st, 'P', "/Users/pierre-louis/Documents/C/Project_So_long/sprite/player.xpm");


    //--------------------

    mlx_key_hook(mlx_st.window, key_listen, &mlx_st);
    mlx_hook(mlx_st.window, 17, (1L<<19), exit_cross, NULL);
    mlx_loop(mlx_st.mlx); 
}