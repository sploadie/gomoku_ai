/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:47:08 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/17 13:07:32 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int		main(int argc, char *argv[])
{
	int		fd;
	t_board	*board;

	if (argc > 2)
	{
		dprintf(2, "Usage: %s [FILE]\n", argv[0]);
		return 1;
	}
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Input");
			return 1;
		}
	}
	board = read_board(fd);
	print_board(board);
	return 0;
}
