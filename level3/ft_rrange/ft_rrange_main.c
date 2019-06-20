/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 00:46:39 by yijhuang          #+#    #+#             */
/*   Updated: 2019/04/08 16:59:02 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{	
	int size;
	int *ret;
	int i;

	i = 0;
	if (end >= start)  //以两个数字的谁大作为分割条件
		size = end - start + 1;
	else
	 	size = start - end + 1;
	if (!(ret = (int*)malloc(sizeof(size))))
		return (0);
	while (i < size)
	{
		if (start > end)
		{
			ret[i] = end + i;
		}
		else
		{
			ret[i] = end - i;
		}
		i++;
	}
	return (ret);
}

int main()
{
	int i;
	int *a = ft_rrange(0, -3);
	for(i=0;i< 4;i++)
		printf("%d ",a[i]);
}