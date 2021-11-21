#include "./include/header.h"

void exit_func(void* params)
{
    exit(0);
}

int key_listen(int keycode, void* params)
{
    ft_printf("keycode : %d\n", keycode);
    if (keycode == 53)
        exit_func(params);
    return 0;
}

int main(void)
{
    mlx_t mlx_st;
    mlx_st.mlx = mlx_init();
    mlx_st.window = mlx_new_window(mlx_st.mlx, 500, 500, "So_long");
    mlx_key_hook(mlx_st.window, key_listen, &mlx_st);
    mlx_loop(mlx_st.mlx); 
}