/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:27:59 by yijhuang          #+#    #+#             */
/*   Updated: 2019/01/27 14:31:00 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void putchar(char c)
{
	write (1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char last_word(char *str)
{
	int i;

	i = 0;
	while (str[i])// 首先走到字符串末尾
	{
		i++;
	}
	i--;//从字符串最后一个字符开始看
	while (is_space(str[i]))
		i--;
	while (str[i] && !is_space(str[i]))
		i--;
	i++;
	while (str[i] && !is_space(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (*str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		last_word(av[1]);
	}
	else
	{
		putchar('\n');
	}
	return (0);
}
