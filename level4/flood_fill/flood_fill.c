/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:16:35 by yijhuang          #+#    #+#             */
/*   Updated: 2019/06/17 20:38:40 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"


void  flood_fill(char **tab, t_point size, t_point begin)
{
    char c;
    t_point current;

    c = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'F';
    //看右边的一个点是否存在，同时这个点是否是相同的字符
    if ((begin.x + 1 < size.x) && (tab[begin.y][begin.x+1] == c))
        {
            current.x = begin.x + 1;
            current.y = begin.y;
            flood_fill(tab, size, current);
        }
    //看左边的一个点是否存在，同时这个点是否是相同的字符
    if ((begin.x > 0) && (tab[begin.y][begin.x-1] == c))
        {
            current.x = begin.x - 1;
            current.y = begin.y;
            flood_fill(tab, size, current);
        }
    //看下边的一个点是否存在，同时这个点是否是相同的字符
    if ((begin.y + 1 < size.y) && (tab[begin.y+1][begin.x] == c))
        {
            current.x = begin.x;
            current.y = begin.y + 1; 
            flood_fill(tab, size, current);
        }
    //看上边的一个点是否存在，同时这个点是否是相同的字符
    if ((begin.y > 0) && (tab[begin.y - 1][begin.x] == c))
        {
            current.x = begin.x;
            current.y = begin.y - 1;
            flood_fill(tab, size, current);
        }
}