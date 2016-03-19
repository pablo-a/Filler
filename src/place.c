/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:10:10 by pabril            #+#    #+#             */
/*   Updated: 2016/03/19 19:08:57 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIECE current->piece->piece
#define PLATEAU current->plateau->plateau

#include "filler.h"

int		place_high_left(t_current *current, char c)
{
	int x;
	int y;

	y = 0;
	while (y < current->plateau->Y)
	{
		x = 0;
		while(x < current->plateau->X)
		{
			if (can_place(current, x, y, c))
				return(ft_printf("%d %d\n", y, x));
			x++;
		}
		y++;
	}
	return (0);
}

int		place_high_right(t_current *current, char c)
{
	int x;
	int y;

	x = current->plateau->X;
	while (x >= 0)
	{
		y = 0;
		while (y < current->plateau->Y)
		{
			if (can_place(current, x, y, c))
				return(ft_printf("%d %d\n", y, x));
			y++;
		}
		x--;
	}
	return (0);
}

int		place_low_right(t_current *current, char c)
{
	int x;
	int y;

	y = current->plateau->Y;
	while (y >= 0)
	{
		x = current->plateau->X;
		while(x >= 0)
		{
			if (can_place(current, x, y, c))
				return(ft_printf("%d %d\n", y, x));
			x--;
		}
		y--;
	}
	return (0);
}

int		place_low_left(t_current *current, char c)
{
	int x;
	int y;

	x = 0;
	while (x < current->plateau->X)
	{
		y = current->plateau->Y;
		while (y >= 0)
		{
			if (can_place(current, x, y, c))
				return(ft_printf("%d %d\n", y, x));
			y--;
		}
		x++;
	}
	return (0);
}
