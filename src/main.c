/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:33:04 by pabril            #+#    #+#             */
/*   Updated: 2016/03/19 15:17:12 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_current	current;
	int			tab[5] = {0, 0, 0, 0, 0};

	init_struct(&current, tab);
	lecture(&current, tab);
	//resolution(&current);
	return (0);
}
