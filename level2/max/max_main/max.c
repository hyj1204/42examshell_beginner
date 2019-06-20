/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:56:54 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 18:40:28 by yijhuang         ###   ########.fr       */
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
	while (i > 0)
	{
		if (tab[i] <= tab[i - 1])
			max = tab[i - 1];
		i--;
	}
	}
	return (max);
}

int main()
{
	int a[] = {-17,-1,17,-2,-11,4,-5,-16,2,15,-17,15,11,2,-17,7,-18,-12,-10,1,-6,14,0};
	printf("%d\n", max(a, 23));
}
