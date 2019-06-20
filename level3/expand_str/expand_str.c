/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:26:33 by yijhuang          #+#    #+#             */
/*   Updated: 2019/02/07 11:26:39 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char  expand_str(char *str)
{
  int i;
  int mark; //用make做标记，按顺序wirte即可

  i = 0;
  mark = 0;
  while (str[i] == ' ' || str[i] == '\t')
			i++;
  while (str[i])//去除空格之后，在字符串存在的情况下
		{
			if (str[i] == ' ' || str[i] == '\t')  //针对每个字符做标记，当遇到有空格的地方就标记为1,等于让程序处于暂停状态
				mark = 1;
			if (str[i] != ' ' && str[i] != '\t')
			{
				if (mark)
          write(1, "   ", 3);//如果之前是空格（即标记为1，暂停状态），即显示三个空格，然后把标记改为0
		    mark = 0;
        write(1, &str[i], 1);
      }
      i++;
    }
    return (*str);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(1, "\n", 1);
    }
    else
    {
        expand_str(av[1]);
        write(1, "\n", 1);
    }
    return (0);
}
