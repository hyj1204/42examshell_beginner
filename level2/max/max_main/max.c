/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:56:54 by exam              #+#    #+#             */
/*   Updated: 2019/08/26 13:32:42 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int max(int* tab, unsigned int len)
{
	int i;
	int max;
	
	i = len - 1;
	if (tab == NULL || len <= 0)
	{
		return (0);
	}
	else if (len == 1)
	{
		return (tab[0]);
	}
	else
	{
		max = tab[i];
	while (i >= 0)
	{
		if (tab[i] >= max)
			max = tab[i];
		i--;
	}
	}
	return (max);
}

int main()
{
	int a[] = {6,-1,3,-8,1,1,7,-12,15,-3,2,7,-7,11,13,-1,-8,-12};
	printf("%d\n", max(a, 18));
}