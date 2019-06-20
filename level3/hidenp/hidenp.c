/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:23:39 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 22:09:18 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int str_len(const char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char hidenp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
		{
			j++;
			i++;
		}
		else
			j++;
	}
	if ( i == str_len(s1))
		write(1, "1", 1);
	else 
		write(1, "0", 1);
	return (*s1);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
	}
	else
	{
		hidenp(av[1], av[2]);
		write(1, "\n", 1);
	}
	return (0);
}
