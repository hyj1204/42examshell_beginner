/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:18:48 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 09:48:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char putchar(char c)
{
	write(1, &c, 1);
	return (c);
}

char s_and_r(char *str, char *a, char *b)
{
	int i;
	int la;
	int lb;
	
	i = 0;
	la = 0;
	lb = 0;
	while (a[i])
		i++;
	la = i;
	i = 0;
	while (b[i])
        i++;
    lb = i;
	i = 0;
	if (la == 1 && lb == 1)
	{
		while (str[i])
		{
			if (str[i] == a[0])
				str[i] = b[0];
			putchar(str[i]);
			i++;
		}
	}
	return (*str);
}

int main(int ac, char **av)
{
	if (ac != 4)
		putchar('\n');
	else
	{
		s_and_r(av[1], av[2], av[3]);
		putchar('\n');
	}
	return (0);
}
