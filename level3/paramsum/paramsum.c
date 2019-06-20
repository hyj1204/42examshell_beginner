/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:43:57 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/23 12:08:22 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putchar(char c)
{
  write(1, &c, 1);
}
void putnbr(int num) //把数字显示出来
{
  if(num < 10)
  putchar('0' + num); //如果是0-9 就直接显示
  else
{
  putnbr(num / 10);  //如果超过10，就通过递归来实现
  putchar(num % 10 + '0');
  //所有当数字大于等于10的时候都要执行putnbr(num / 10);和putchar(num % 10 + '0');这两条命令
  //由于putnbr(num/10)就是函数本身所以继续执行时需要最后一个执行完毕后再一次返回，执行相应的命令
/*|-putnbr(1234/10)
    |--putnbr(123/10)
       |--putnbr(12/10)
          |--putnbr(1)
          |--putchar('0' + 1) //显示1
          |--return //函数putnbr(1)
       |--putchar(12 % 10 + '0') //显示2
       |--return //函数putnbr(12/10)
    |--putchar(123 % 10 + '0') //显示3
    |--return //函数putnbr(123/10)
  |--putchar(1234 % 10 + '0') //显示4
  |--return //函数putnbr(1234/10)
  */
} 
  
} 
int main(int ac, char **av)
{
    if (av[1])// for pass gcc 3W check
    putnbr(ac - 1); //这个数字从1开始，所以这边不考虑数字为负的情况
    else
        putnbr(0);
    putchar('\n');
    return (0);
}