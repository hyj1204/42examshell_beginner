/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_str_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:11:58 by yijhuang          #+#    #+#             */
/*   Updated: 2019/02/07 15:12:01 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		if_char_within_base(char c, int str_base) //输入字符和进制数，判断这个字符是不是在它所对应的进制内
{
	if (str_base <= 10)     //如果是十进制以内，则判断这个字符是不是在0-9的范围内
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + str_base - 10)) || \
	(c >= 'a' && c <= ('a' + str_base - 10))); //否则的话，就判断这个字符是不是0-9，或者是不是在它对应进制的字符范围内（大小写都包含）
}

int ft_atoi_base(const char *str, int str_base)
{
  int		i;
  int		nbr;
  int		sign;

  if (!str[0] || (str_base < 2 || str_base > 16))//如果字符串的第一个字符不存或者进制数在（1及1一下，17及17以上）
  		return (0);
  i = 0;
  nbr = 0;
  sign = 1;
  while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || \
  		str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
  		i++;    //清除开头的零
  if (str[i] == '-' || str[i] == '+')
  		if (str[i++] == '-')
  		  sign *= -1; //如果第一个是负号就把sign变负
  while (str[i] && if_char_within_base(str[i], str_base))//如果字符串存在并且这些字符在它对应进制内
  	{
  		if (str[i] >= 'A' && 'F' >= str[i]) //如果是大写字符
  			nbr = (nbr * str_base) + (str[i] - 'A' + 10);  //则数字是 （之前计算出来的数字 * 进制） + 那个字符代表的十进制数
  		else if (str[i] >= 'a' && 'f' >= str[i]) //如果是小写字符,原理同上
  			nbr = (nbr * str_base) + (str[i] - 'a' + 10);
  		else
  			nbr = (nbr * str_base) + (str[i] - '0');
  		i++;
  	}
  	return (nbr * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int		i;

	i = 0;
  if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}
}

int main(int ac, char **av)
{
    int i;
    i = 2;
    if (ac == 1)
    {
        write (1, "\n", 1);
    }
    else
    {
        ft_putnbr(ft_atoi_base(av[i-1], 16));
        write (1, "\n", 1);
    }
    return (0);
}
