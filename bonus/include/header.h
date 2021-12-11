/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:50:09 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 16:43:57 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libs/minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "../libs/libft/libft.h"
# include "../libs/Get_Next_Line/get_next_line.h"

typedef struct s_map
{
	int	max_x;
	int	max_y;
}	t_map;

typedef struct s_map_sprite
{
	void	*sand;
	void	*wall;
	void	*item;
	void	*door;
	void	*tomb;
	void	**fire;
}	t_map_sprite;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	void	*player_sprite;
	int		skin_width;
	int		skin_height;
	int		count_move;
	int		want_exit;
	int		will_die;
	void	**sprite_liste;
}	t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	char			**map_b;
	int				count_item;
	t_player		*player;
	t_map			*map_size;
	t_map_sprite	*map_sprite;
}	t_mlx;

int			calc_map_size(char **buffer, t_map *map);
int			check_close(char **buffer, t_map *map);
int			valid_map(char **buffer);
int			check_piece_here(char **buffer, char c);
void		*put_image(t_mlx *mlx_st, void *img, int x, int y);
void		exit_func(void *params);
void		put_sprite(t_mlx *mlx_st, char c, void *img);
int			check_all_piece(char **buffer);
void		init_player_struct(t_player *player);
char		**put_buffer(char *path);
void		refresh_map(t_mlx *mlx_st);
void		cond2(t_mlx *mlx_st, int x, int y);
void		cond1(t_mlx *mlx_st, int x, int y);
int			go_up(t_mlx *mlx_st);
int			go_down(t_mlx *mlx_st);
int			go_left(t_mlx *mlx_st);
int			go_right(t_mlx *mlx_st);
void		free_map(char **buffer);
void		exit_func(void *params);
int			exit_cross(int keycode, void *params);
void		player_win(t_mlx *mlx_st);
void		stock_sprite_player(t_mlx *mlx_st, int player_count_sprite);
void		stock_sprite_enemy(t_mlx *mlx_st, int enemy_count_sprite);
void		frame_enemy(t_mlx *mlx_st, int index);
int			renderer_next_frame(t_mlx *mlx_st);
#endif