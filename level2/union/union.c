/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:09:28 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 22:05:29 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int str_len(char *str)  //计算字符串长度
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int check_dup(char a, char *str) //检查某个字符是否在字符串中
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] ==  a)
			return (1);
		i++;
	}
	return (0);
}

char  union_str(char *s1, char *s2)
{
	int i;
	int j;

	i = str_len(s1);
	j = str_len(s2);
	char ret[i + j + 1];  //建立一个两个字符串大小的数组
	char dup[str_len(s1) + str_len(s2)]; //再新建一个新的两个字符串大小的字符数组
	i = 0;
	j = 0;
	while (i < str_len(s1))  //先把第一个字符串放入
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < (str_len(s1) + str_len(s2)))  //再把第二个字符串放入
    {
        ret[i] = s2[j];
        i++;
		j++;
    }
	ret[i] = '\0';  //最后加null terminal，ret里面存了两个字符串的所有字符

	i = 0;
	j = 0;
	while (ret[i])
	{
		if(check_dup(ret[i], dup)) //检查当前这个字符是否在新的空白数组中
		{
			i++;  //如果在里面就在ret里跳过这个字符，走到下一个字符
		}
		else
		{
			write(1, &ret[i], 1);  //如果不再里面就显示并加入这个数组
			dup[j] = ret[i];
			j++;
			i++;
		}
	}
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
		union_str(av[1], av[2]);
		write(1, "\n", 1);
	}
	return (0);
}
