/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:48:42 by yijhuang          #+#    #+#             */
/*   Updated: 2019/06/20 13:22:34 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
  int i;
  int num;

  if (ac == 2)
  {
    num = atoi(av[1]);
    i = 2;
    if (num == 1)
      printf("1");
    while (i <= num)   //从2开始一直试到数字本身
    {
      if (num % i == 0)   //发现有数可以除尽它的的时候，显示该数和*
      {
        printf("%d", i);
        if (num == i) //如果i到了最大（和它本身相同）就跳出这个循环
          break ;
        printf("*");
        num = num / i;//显示完之后把除剩下的这个数，再重新从2开始除
        i = 1;
      }
      i++;
    }
  }
  printf("\n");
  return (0);
}
