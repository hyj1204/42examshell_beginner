/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:31:37 by yijhuang          #+#    #+#             */
/*   Updated: 2018/06/07 20:23:05 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int 	main(int argc, char **argv)

{
	if (argc != 3)
	{
		write(1, "\n", 1);
	}
	else
	{
		int num1;
		int num2;
		int max;
		int i;

		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		i = 1;
		max = 1;
		
		if (num1 == num2)
			printf("%d\n", atoi(argv[1]));
   		if (num1 > num2)
		{
			while (i <= num2)
			{
				if ((num1 % i == 0) && (num2 % i == 0))
				{
					max = i;
					i++;
				}
				else
				{
					i++;
				}
			}
			printf("%d\n",max);
		}
		else
		{
			while (i <= num1)
			{
				if ((num1 % i == 0) && (num2 % i == 0))
				{
					max = i;
					i++;
				}
				else
				{
					i++;
				}
			}
			printf("%d\n", max);
		}
	}
	return (0);
}
