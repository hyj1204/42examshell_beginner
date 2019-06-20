/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:10:11 by exam              #+#    #+#             */
/*   Updated: 2019/05/08 00:04:45 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ft_atoi(const char *str)
{
	int i;
	int num;
	int flag;

	i = 0;
	num = 0;
	flag = 1;
	if (str[0] == '-')
	{
		flag = -1;
		i++;
	}
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return flag * num;
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return flag * num;
}

int main()
{
	int num;
	int ft_num;

	num = atoi("2147483649");
	ft_num = ft_atoi("2147483649");
	printf("num = %d\n", num);
	printf("ft_num = %d\n", ft_num);
	printf("int_min = %d\n", INT_MIN);
	printf("int_max = %d\n", INT_MAX);
}
