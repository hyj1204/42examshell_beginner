/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:00:17 by yijhuang          #+#    #+#             */
/*   Updated: 2019/06/10 16:19:00 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"   //包含t_list的头文件

int    ft_list_size(t_list *begin_list) //放进去一个t_list的指针，看这个linked list里面有几个元素
{
  int i;
  t_list *list; //定义一个指针，指向输入的指针地址

  i = 0;
  list = begin_list; //指向输入地址
  if (list == 0)
    return (0);
  while (list != 0)//当指向的地址不是null的时候
  {
      i++;
      list = list->next;
  }
  return (i);
}
