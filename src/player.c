/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:25:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/17 19:35:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

t_player	player_create(int color, int maximizing)
{
	t_player player;

	player.color = color;
	player.maximizing = maximizing;
	return player;
}

t_player	player_switch(t_player player)
{
	if (player.color == 'w')
		player.color = 'b';
	else
		player.color = 'w';
	if (player.maximizing)
		player.maximizing = 0;
	else
		player.maximizing = 1;
	return player;
}
