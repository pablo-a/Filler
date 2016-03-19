/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:42:11 by pabril            #+#    #+#             */
/*   Updated: 2016/03/19 15:27:12 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIECE current->piece->piece
#define PLATEAU current->plateau->plateau

#include "filler.h"
#include "ft_printf.h"

void	resolution(t_current *current)
{
	int x;
	int y;

	y = 0;
	while (y !<= (current->plateau->Y - current->piece->Y))
	{
		x = 0;
		while (x <= current->plateau->X - current->piece->X)
		{
			if (can_place_piece(current, x, y, current->mysign))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	ft_printf("0 0\n");
}

int		can_place_piece(t_current *current, int x, int y, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	j = 0;
	while (j != current->piece->Y)
	{
		i = 0;
		while (i != current->piece->X)
		{
			if ((PIECE[j][i] == '*') &&
			(PLATEAU[y + j][x + i] == c || PLATEAU[y + j][x + i] == c - 32))
				count++;
			else if ((PIECE[j][i] == '*') && (PLATEAU[y + j][x + i] != '.') && PLATEAU[y + j][x + i] != 'c' && PLATEAU[y + j][x +i] != c - 32)
				return (0);
			if (count > 1)
				return (0);
			i++;
		}
		j++;
	}
	if (count == 0)
		return (0);
	return (1);
}
