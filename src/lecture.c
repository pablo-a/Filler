/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:40:29 by pabril            #+#    #+#             */
/*   Updated: 2016/03/18 21:44:16 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_lecture(t_current *current)
{
	char	*str;
	char	**tab;

	get_next_line(0, &str);
	tab = ft_strsplit(str, ' ');
	if (ft_strcmp(tab[0], "$$$") == 0) // multi-player
	{
		current->player = ft_atoi(&tab[2][1]);
		if (current->player == 1)
			current->mysign = 'o';
		else
			current->mysign = 'x';
		lecture(current);
	}
	else//								// solo-player
		fill_plateau(current, tab);
}

void	fill_plateau(t_current *current, char **tab)
{
	int		i;
	char	*str;

	i = 0;
	current->plateau->Y = ft_atoi(tab[1]);
	current->plateau->X = ft_atoi(tab[2]);
	if ((current->plateau->plateau = (char **)malloc(sizeof(char *) *
					(current->plateau->Y + 1))) == 0)
		perror("wasnt able to allocate memory for the gameboard");
	get_next_line(0, &str);
	while (i < (current->plateau->Y))
	{
		if (get_next_line(0, &str) < 0)
			return (ft_putendl("not able to read the map"));
		(current->plateau->plateau)[i] = ft_strsub(str, 4, current->plateau->X);
		//printf("%s\n", current->plateau->plateau[i]);
		i++;
	}
	get_piece(current);

}

void	lecture(t_current *current)
{
	char	*str;
	char	**tab;
	int		i;

	i = 0;
	if (get_next_line(0, &str) < 1)
		return (ft_putendl("unable to read input correctly"));
	tab = ft_strsplit(str, ' ');
	fill_plateau(current, tab);
}

void	get_piece(t_current *current)
{
	char *str;
	char	**tab;
	int		i;

	i = 0;
	if (get_next_line(0, &str) < 1)
		return (ft_putendl("unable to read input correctly"));
	tab = ft_strsplit(str, ' ');
	current->piece->X = ft_atoi(tab[2]);
	current->piece->Y = ft_atoi(tab[1]);
	if ((current->piece->piece = (char **)malloc(sizeof(char *) *
					(current->piece->Y + 1))) == 0)
		perror("wasnt able to allocate memory for the gameboard");
	while (i <= (current->piece->Y))
	{
		if (get_next_line(0, &str) < 0)
			return (ft_putendl("not able to read the map"));
		current->piece->piece[i] = ft_strnew(current->piece->X);
		ft_strncpy((current->piece->piece)[i], str, current->piece->X);
		//printf("%s\n", current->piece->piece[i]);
		i++;
	}
}

int		init_struct(t_current *current)
{
	current->player = 0;
	current->piece = (t_piece *)malloc(sizeof(t_piece));
	current->plateau = (t_plateau *)malloc(sizeof(t_plateau));
	return (0);
}
