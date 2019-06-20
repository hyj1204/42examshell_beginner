/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:25:33 by yijhuang          #+#    #+#             */
/*   Updated: 2019/02/25 12:46:19 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_char(char c)
{
		write(1, &c, 1);
}

char str_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == ' ')
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		i++;
		while (str[i] && str[i] != '\t' && str[i] != ' ')
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
			i++;
		}
	}
	i = 0;
	while (str[i])
	{
		put_char(str[i]);
		i++;
	}
	return (*str);
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		while (av[i])
		{
			str_capitalizer(av[i]);
			put_char('\n');
			i++;
		}
	}
	return (0);
}
