/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:35:20 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:15 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	init_player_struct(t_player *player)
{
	player->count_move = 0;
	player->pos_x = 0;
	player->pos_y = 0;
	player->skin_height = 64;
	player->skin_width = 64;
	player->sprite = NULL;
	player->want_exit = 0;
	player->will_die = 0;
}
