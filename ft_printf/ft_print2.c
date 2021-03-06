/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:23:11 by pabril            #+#    #+#             */
/*   Updated: 2016/02/26 11:06:12 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_print_zeros(int secure, int len)
{
	int a;

	if (secure <= len)
		return (0);
	a = secure - len;
	while (secure > len)
	{
		write(1, "0", 1);
		secure--;
	}
	return (a);
}
