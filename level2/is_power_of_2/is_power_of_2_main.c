/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:17:24 by yijhuang          #+#    #+#             */
/*   Updated: 2018/06/06 17:21:24 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_power_of_2(unsigned int n)
{
	printf("input = %d\n", n);
	if (n == 0)
		return (0);
	else if (n == 1)
	   return (1);
	else
	{
		while (n % 2 == 0)
		{
			n = n / 2;  //在可以除尽2的情况下，把除出来的数继续返回除以2，例如；10/2（余数是0） = 5，再把5/2 = 2.5这样就产生余数了,此时n是5.
		}
		if (n == 1)
			return (1); //如果可以一直除以2，最后n肯定等于2/2 =1
		else
			return (0); //其他情况的话就不是2的次方power
	}
}

int main()
{
	printf("output = %d\n", is_power_of_2(-1));
	return (0);
}
