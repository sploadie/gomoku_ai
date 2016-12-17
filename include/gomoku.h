/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:47:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/17 14:21:22 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_H
# define GOMOKU_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifdef USE_INT
typedef int				t_space;
# else
typedef unsigned char	t_space;
# endif

typedef struct			s_board
{
	t_space				map[15][15];
	int					black;
	int					white;
}						t_board;

typedef struct			s_pos
{
	int					x;
	int					y;
	int					h;
}						t_pos;

t_board		*read_board(int fd);
void		print_board(t_board *board);

void		*memdup(void *data, size_t len);

#endif
