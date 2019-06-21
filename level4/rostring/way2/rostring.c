/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:29:36 by exam              #+#    #+#             */
/*   Updated: 2019/06/20 20:28:42 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void f_putc(char c)
{
	write(1, &c, 1);
}

int rostring(char *str)
{
	int i;
	int j;
	int fwlen;
	int ftime;
	char *fw;
	int only_word;

	fw = 0;
	i = 0;
	j = 0;
	fwlen = 0;
	ftime = 1;
	only_word = 1;
	while (str[j])
	{
		while (str[j] == ' ' || str[j] == '\t')
			j++;   //遇到空格就跳过
		if (ftime == 1 && str[j])  //遇到第一个单词的时候，计算第一个单词的长度
		{
			while (str[j] && str[j] != ' ' && str[j] != '\t')
			{
				fwlen++;
				j++;
			}  //走到空格处	
			ftime = 2;
		}

		if (ftime == 2) //如果有第一个字符,保存第一个单词
		{
			if (!(fw = (char*)malloc(fwlen + 1)))
				return 0;
			j = j - fwlen;
			while (i < fwlen)
			{
				fw[i] = str[j];
				i++;
				j++; //保存第一个单词在fw，移到后一格（空格/或者\0）
			}
			ftime = 0;
		}

		if (str[j] && ftime == 0) //已经保存了第一个单词的情况下，看后面还有没有单词
		{
				while (str[j] == ' ' || str[j] == '\t')
					j++;
				while (str[j] && str[j] != ' ' && str[j] != '\t')
				{
					f_putc(str[j]);
					j++;
					only_word = 0;
				}
				if (only_word == 0)
					f_putc(' '); //只有第二个单词的结尾开始加空格
		}


	}
	if (fw != 0)  //走到结束加上第一个单词
		{
			i = 0;
			while (i < fwlen)
			{
				f_putc(fw[i]);
				i++;
			}
		}
	return 0;
}

int main(int ac, char **av)
{
	if (ac >= 2)
		rostring(av[1]);
	f_putc('\n');
	return 0;
}

