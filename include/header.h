#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../ft_printf/includes/ft_printf.h"
#include "../Get_Next_Line/get_next_line.h"

typedef struct mlx_s
{
    void *mlx;
    void *window;
 
} mlx_t;

typedef struct map_s
{
    int max_x;
    int max_y; 
} map_t;

int calc_map_size(map_t *map);
int check_close(map_t *map);
int valid_map();
int check_piece_here(char c);
void put_image(mlx_t mlx_st, char *imgPath, int x, int y);
void exit_func(void* params);
int put_sprite(mlx_t mlx_st, char c, char* path);
int check_all_piece();