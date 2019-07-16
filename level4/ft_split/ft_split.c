/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:09:42 by yijhuang          #+#    #+#             */
/*   Updated: 2019/07/15 22:54:56 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// #include <stdio.h>

int is_space(char c)
{
    if (c == '\t' || c == '\n' || c == ' ') 
        return 1;
    else
        return 0;    
}

int		ft_wordcount(char const *str)   //得出一共有几个单词
{
	int		row;
	int		i;

	row = 0;
	i = 0;
	if (!str)
		return (0);
	// printf("str = %s\n", str);
	while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
		if (str[i])
		{
			row++;
			while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
				i++;
		}	
    }
	// printf("row = %d\n", row);
    return row;
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	
	if (!s || !(new = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (len--)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int		ft_wordlen(char const *s)
{
	int i;

	i = 0;
	while (!(is_space(s[i])) && s[i])
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	char	**board;
	int		i;
	int		numwords;
	int		wlen;

	numwords = ft_wordcount(str);
	if(!(board = (char**)malloc((numwords + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (numwords)
	{
		while (is_space(*str))
			str++;  //这里直接动str指针的位置
		wlen = ft_wordlen(str); //算出这个单词的长度
		if (!(board[i] = ft_strsub(str, 0, wlen))) //给每一行赋值，因为这里有malloc所以有可能返回null，所以要检查。
			return (NULL);
		str += wlen;
		i++;
        numwords--;
	}
	board[i] = NULL; //最后一行返回null
	return (board);
}


