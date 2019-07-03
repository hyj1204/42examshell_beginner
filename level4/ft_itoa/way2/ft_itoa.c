/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:58:33 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 12:04:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa(int nbr)
{
	int len;
	char *str_n;
	int tmp_n;
	int num;
	
	
	len = 0;
	str_n = 0;
	tmp_n = 0;
	num = 0;
	if (nbr == -2147483648)
	{
		str_n = (char*)malloc(sizeof(char) * 12);
		str_n[0] = '-';
		str_n[1] = '2';
		str_n[2] = '1';
		str_n[3] = '4';
		str_n[4] = '7';
		str_n[5] = '4';
		str_n[6] = '8';
		str_n[7] = '3';
		str_n[8] = '6';
		str_n[9] = '4';
		str_n[10] = '8';
		str_n[11] = '\0';
		return str_n;

	}		
	else if (nbr > 0)
	{
		tmp_n = nbr;
		while (tmp_n > 0)
		{
			len++;
			tmp_n = tmp_n / 10;
		}
		str_n = (char*)malloc(len + 1);
		tmp_n = len;
		while (len > 0)
		{
			str_n[len - 1] = '0' + nbr % 10;
			nbr = nbr / 10;
			len--;
		}
		str_n[tmp_n] = '\0';
		return str_n;
	}
	else if (nbr < 0)
	{
		tmp_n = -nbr;
		num = -nbr;
		while (tmp_n > 0)
		{
			len++;
			tmp_n = tmp_n / 10;
		}
		str_n = (char*)malloc(sizeof(char) * (len + 2));
		tmp_n = len;
		while (len > 0)
		{
			str_n[len] = '0' + num % 10;
			num = num / 10;
			len--;
		}
		str_n[tmp_n + 1] = '\0';
		str_n[0] = '-';
		return str_n;
	}
	else
	{
		str_n = (char*)malloc(sizeof(char) * 2);
		str_n[0] = '0';
		str_n[1] = '\0';
		return str_n;
	}
	return 0;
}
