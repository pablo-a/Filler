/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:40:29 by pabril            #+#    #+#             */
/*   Updated: 2016/03/18 12:04:52 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_lecture(t_current *current)
{
	char *str;
	char **tab;
	int		count;

	count = 0;
	while (get_next_line(0, &str))
	{
		count ++;
		tab = ft_strsplit(str, ' ');
		if (ft_strncmp(tab[4], "[pabril]", 8) == 0)
		{
			if ((current->player = (int)(tab[2][1] - '0')) == 1 || ((current->player) == 2))
			{
				get_next_line(0, &str);
				break ;
			}
			else
				return (perror("not a correct player number"));
		}
		if (count == 2)
			return (perror("not able to read a player number"));
		free(tab);
	}
	lecture(current);
	return ;
}

int		lecture(t_current *current)
{
	printf("player number = %d\n", current->player);
	return (0);
}
