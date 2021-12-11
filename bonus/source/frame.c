/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:31:32 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	stock_sprite_player(t_mlx *mlx_st, int player_count_sprite)
{
	char	*number;
	char	*string;
	char	*end;
	int		i;

	i = 0;
	mlx_st->player->sprite_liste = malloc(sizeof(void *)
			* player_count_sprite + 1);
	while (i < player_count_sprite)
	{
		number = ft_itoa(i + 1);
		string = ft_strjoin("bonus/sprite/player/player", number);
		free(number);
		end = ft_strjoin(string, ".xpm");
		free(string);
		mlx_st->player->sprite_liste[i] = mlx_xpm_file_to_image(mlx_st->mlx,
				end, &mlx_st->player->skin_width, &mlx_st->player->skin_height);
		free(end);
		i++;
	}
	mlx_st->player->sprite_liste[i] = NULL;
}

void	stock_sprite_enemy(t_mlx *mlx_st, int enemy_count_sprite)
{
	char	*number;
	char	*string;
	char	*end;
	int		i;

	i = enemy_count_sprite - 1;
	mlx_st->map_sprite->fire = malloc(sizeof(void *) * enemy_count_sprite + 1);
	while (i >= 0)
	{
		number = ft_itoa(i + 1);
		string = ft_strjoin("bonus/sprite/fire/fire", number);
		free(number);
		end = ft_strjoin(string, ".xpm");
		free(string);
		mlx_st->map_sprite->fire[i] = mlx_xpm_file_to_image(mlx_st->mlx,
				end, &mlx_st->player->skin_width, &mlx_st->player->skin_height);
		free(end);
		i--;
	}
	mlx_st->map_sprite->fire[i] = NULL;
}

void	frame_enemy(t_mlx *mlx_st, int index)
{
	int	i;
	int	y;

	y = 0;
	while (mlx_st->map_b[y] != NULL)
	{
		i = 0;
		while (mlx_st->map_b[y][i] != '\0')
		{
			if (mlx_st->map_b[y][i] == 'N')
			{
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->window,
					mlx_st->map_sprite->sand, i * 64, y * 64 + 64);
				mlx_put_image_to_window(mlx_st->mlx, mlx_st->window,
					mlx_st->map_sprite->fire[index], i * 64 + 10, y * 64 + 64);
			}
			i++;
		}
		y++;
	}		
}

void	refresh_skin(t_mlx *mlx_st, int i)
{
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->window,
		mlx_st->map_sprite->sand, mlx_st->player->pos_x * 64,
		mlx_st->player->pos_y * 64 + 64);
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->window,
		mlx_st->player->sprite_liste[i], mlx_st->player->pos_x * 64,
		mlx_st->player->pos_y * 64 + 64);
}

int	renderer_next_frame(t_mlx *mlx_st)
{
	static int	i = 0;
	static int	y = 0;
	static int	int_enemy = 0;

	if (int_enemy == 14)
		int_enemy = 0;
	if (i == 8)
		i = 0;
	if (y == 10000)
		y = 0;
	if (mlx_st->player->will_die == 1 || (mlx_st->count_item == 0
			&& mlx_st->player->want_exit))
		player_win(mlx_st);
	else if (y % 1000 == 0)
	{
		refresh_skin(mlx_st, i);
		if (y % 2000 == 0)
			frame_enemy(mlx_st, int_enemy);
		i++;
	}
	y++;
	int_enemy++;
	return (0);
}
