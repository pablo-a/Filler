/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:42:11 by pabril            #+#    #+#             */
/*   Updated: 2016/03/18 18:44:33 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		resolution(t_current *current)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y != (current->plateau->Y) + 1)
	{
		while (x != current->plateau->X + 1)
		{
			if (can_place_piece(current, x, y))
			{
				ft_printf("%d %d", y, x);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (ft_putendl("cannot place this piece in the grid, sorry"));
}

int		can_place_piece(t_current *current, int x, int y)
{
	return (0);
}
