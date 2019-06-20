/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:01:42 by exam              #+#    #+#             */
/*   Updated: 2019/02/14 10:26:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	putchar(char c)
{
	write(1, &c, 1);
	return (c);
}

char wdmatch(char* str1, char*str2)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (str1[len]) //获得第一个字符串的长度
		len++;
	i = 0;
	while (str2[j]) //在第二个字符串存在时候
	{
		if (str1[i] && (str1[i] == str2[j])) //当第二个字符串里出现第一个字符串的字符时，i就+1
				i++;
		j++;
	}
	if (i == len) //看结束的时候，是不是在2里出现的字符数跟1的长度相同，相同的话就把1全部显示出来。
	{
		i = 0;
		while (str1[i])
		{
			putchar(str1[i]);
			i++;
		}
	}
	return (*str1);
}

int main(int ac, char** av)
{
	int i;

	i = 0;
	if (ac != 3)
		putchar('\n');
	else
	{
		wdmatch(av[1], av[2]);
		putchar('\n');
	}
	return (0);
}
