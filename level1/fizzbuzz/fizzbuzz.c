/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:15:28 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 09:49:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void f_putc(char c)
{
	write(1, &c, 1);
}

void pstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		f_putc(str[i]);
		i++;
	}
}

int num_len(int num)
{
	int len;
	
	len = 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return len;
}


int patoi(int num)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (num < 10)
	{
		f_putc(num + '0');
		return 0;
	}
	else 
	{
		len = num_len(num);
		char str[len];
		while (len > 0)
		{
			str[len-1] = (num % 10) + '0';
			len--;
			num = num / 10;
		}
		f_putc(str[0]);
		f_putc(str[1]);
	}
	return 0;
}


int main()
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			pstr("fizzbuzz");
		else if (i % 5 == 0)
			pstr("buzz");
		else if (i % 3 == 0)
			pstr("fizz");
		else
			patoi(i);
		f_putc('\n');
		i++;
	}
	return 0;
}
