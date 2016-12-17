/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:08:22 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/17 13:24:09 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

void	print_board(t_board *board)
{
	int 	i, j, c;
	char	buf[243];

	c = 0;
	for (i = 0; i < 15; ++i)
	{
		for (j = 0; j < 15; ++j)
			buf[c++] = board->map[i][j];
		buf[c++] = '\n';
	}
	buf[c++] = '0' + board->white;
	buf[c++] = '0' + board->black;
	buf[c] = '\n';
	write(1, buf, 243);
}