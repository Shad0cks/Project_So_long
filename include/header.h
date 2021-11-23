#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../ft_printf/includes/ft_printf.h"
#include "../Get_Next_Line/get_next_line.h"

typedef struct map_s
{
    int max_x;
    int max_y; 
} map_t;

typedef struct player_s
{
    int pos_x;
    int pos_y;
    void *player_sprite;
    int skin_width;
    int skin_height;
    int count_move;
} player_t;

typedef struct mlx_s
{
    void *mlx;
    void *window;
	char **map_b;
	int count_item;
    player_t *player;
    items_t *items;
} mlx_t;

int calc_map_size(map_t *map);
int check_close(map_t *map);
int valid_map();
int check_piece_here(char c);
void *put_image(mlx_t *mlx_st, char *imgPath, int x, int y);
void exit_func(void* params);
int put_sprite(mlx_t *mlx_st, char c, char* path, char **buffer);
int check_all_piece();
void init_player_struct(player_t *player);
char **put_buffer();
void refresh_map(mlx_t *mlx_st);
int go_up(mlx_t *mlx_st);
int go_down(mlx_t *mlx_st);
int go_left(mlx_t *mlx_st);
int go_right(mlx_t *mlx_st);