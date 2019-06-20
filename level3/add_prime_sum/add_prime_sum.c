/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:31:51 by yijhuang          #+#    #+#             */
/*   Updated: 2019/01/31 18:32:22 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - '0');
		i++;
	}
	return ((int)num * sign);
}

int is_prime(int num)   //大于0的时候是质数，等于0的时候不是质数
{
  int i;

  i = 2;
  if (num < 3)
    return (num - 1);//1不是质数也不是合数，2是质数，3是质数(下面算出)
  while (i < num) //除以每一个比这个数小的数（从2开始）
  {
    if (!(num % i)) //如果有遇到余数是0的时候（即可以除尽的时候）
         return (0); //就不是质数
    else
        i++;
  }//如果走到最后都没有数可以除尽，那这个数就是质数。
  return (1);
}

//下面是优化的算法
// int is_prime(int num)   //大于0的时候是质数，等于0的时候不是质数
// {
//   int i;
//
//   i = 2;
//   if (num <= 3)
//     return (num - 1); //1不是质数也不是合数，2是质数，3是质数
//   while (i <= （num / 2）) //然后把这个数依次除以从2开始的每一个数，直到这个数的一半处
//   {
//     if (!(num % i) //如果有遇到余数是0的时候（即可以除尽的时候）
//          return (0); //就不是质数
//     else
//         i++;
//   }
//   return (1);
// }

void	ft_putnbr(int n)  //这里只需要putnbr正数的部分
{
	int		i;

	i = 0;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}
}

int add_prime_sum(int num)
{
  int sum;

  sum = 0;
  while (num > 0)
  {
    if (is_prime(num))
      sum = sum + num;
    num--;
  }
  ft_putnbr(sum);
  return(num);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putchar('0');
        ft_putchar('\n');
    }
    else
    {
      int num;

      num = 0;
      num = ft_atoi(av[1]);
      if (num <= 0)
      {
        ft_putchar('0');
      }
      else
      {
        add_prime_sum(num);
        ft_putchar('\n');
      }
    }
    return (0);
}
