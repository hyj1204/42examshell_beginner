/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:31:37 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/13 13:27:12 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void putchar(char c) {
  write(1, &c, 1);
}

void putstr(char *str) {
    int i;

    i = 0;
    while (str[i])
    {
        putchar(str[i]);
        i++;
    }
}

int words_num(char *str) //计算有几个单词
{
    int i;
    int num;

    i = 0;
    num = 1;
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            num++;
        }
        i++;
    }
    return (num);
}

int rev_wstr(char *str)
{
    int i;
    int x;
    int y;
    int num;
    int len; //代表每个单词的长度
    char **words;


    i = 0;
    num = words_num(str);//得到一共有多少个单词
    len = 0;
    x = 0;
    y = 0;

    if (!(words = (char**)malloc(sizeof(char*) * (num + 1)))) //每个单词放一行，一共有（num + 1)行
        return (0);
    words[num] = NULL;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        { 
            len++;
            i++;
        }
        if (!(words[x] = (char*)malloc(sizeof(char) * len + 1))) //为每个单词创建空间
                return (0);
        x++;
        len = 0;
        if(str[i])
            i++;
    }

    i = 0;
    x = 0;
    while (str[i]!= '\0')
    {
        y = 0;
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        {
            words[x][y] = str[i];   //把每个单词放入相应的空间words[0] 代表第一个单词
            i++;
            y++;
        }
        words[x][y] = '\0';
        x++;
        if(str[i])
            i++;
    }
    while (num > 0)
    {
        putstr(words[num - 1]);  //把每一个单词打印出来
        if (num - 1)
            putchar(' ');  //不是最后一个单词的话后面加空格
        num--;
    }
    return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		rev_wstr(av[1]);
        write(1, "\n", 1);
	}
	return (0);
}
