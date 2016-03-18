/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:33:04 by pabril            #+#    #+#             */
/*   Updated: 2016/03/18 18:18:36 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int argc, const char *argv[])
{
	t_current	*current;
	static int	begin = 1;

	if ((current = (t_current *)malloc(sizeof(t_current))) == NULL)
		return (0);
	if (begin && begin--)
	{
		init_struct(current);
		first_lecture(current);
	}
	else
		lecture(current);
	resolution(current);
	argc = 2;
	begin = 2;
	argv[0] = "easy";
	return (0);
}
