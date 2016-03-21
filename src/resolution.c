/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:42:11 by pabril            #+#    #+#             */
/*   Updated: 2016/03/21 15:19:54 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIECE current->piece->piece
#define PLATEAU current->plateau->plateau

#include "filler.h"
#include "ft_printf.h"

int		avance_j(int i, int j, t_current *current)
{
	while (j != current->piece->Y)
	{
		while (i != current->piece->X)
		{
			if (PIECE[j][i] == '*')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

int		can_place(t_current *current, int x, int y, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	j = avance_j(0, 0, current);
	while (j != current->piece->Y)
	{
		i = 0;
		while (i != current->piece->X)
		{
			if (((y + j) >= current->plateau->Y || (x + i) >=
						current->plateau->X) && PIECE[j][i] != '.')
				return (0);
			if ((PIECE[j][i] == '*') &&
				(PLATEAU[y + j][x + i] == c || PLATEAU[y + j][x + i] == c - 32))
				count++;
			else if ((PIECE[j][i] == '*') && (PLATEAU[y + j][x + i] != '.') &&
				PLATEAU[y + j][x + i] != 'c' && PLATEAU[y + j][x + i] != c - 32)
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

void	resolution(t_current *current)
{
	int			(*place[4])(t_current *current, char c);
	static int	i = 0;
	int			end;

	place[0] = place_high_left;
	place[1] = place_high_right;
	place[2] = place_low_right;
	place[3] = place_low_left;
	end = 0;
	while ((place[i % 4](current, current->mysign) == 0))
	{
		i++;
		end++;
		if (end == 4)
		{
			ft_printf("0 0\n");
			return ;
		}
	}
	i++;
}
