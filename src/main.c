/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:33:04 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 18:49:46 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, const char *argv[])
{
	t_list *lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (0);
	lecture(lst);
	resolution(lst);
	return (0);
}
