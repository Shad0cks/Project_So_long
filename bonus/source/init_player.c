/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:56:20 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/10 05:56:21 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	init_player_struct(player_t *player)
{
	player->count_move = 0;
	player->pos_x = 0;
	player->pos_y = 0;
	player->skin_height = 64;
	player->skin_width = 64;
	player->player_sprite = NULL;
	player->want_exit = 0;
	player->will_die = 0;
	player->sprite_liste = NULL;
}
