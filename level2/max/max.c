/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:56:54 by exam              #+#    #+#             */
/*   Updated: 2019/08/26 13:35:10 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int max(int* tab, unsigned int len)
{
	int i;
	int max;

	i = len - 1;
	if (tab == 0 || len <= 0)
	{
		return (0);
	}
	else if (len == 1)
	{
		return (tab[0]);
	}
	else
	{
	while (i >= 0)
	{
		if (tab[i] >= max)
			max = tab[i];
		i--;
	}
	}
	return (max);
}
