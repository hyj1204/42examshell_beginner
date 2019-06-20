/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:40:20 by yijhuang          #+#    #+#             */
/*   Updated: 2019/04/23 08:35:12 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void inter(char *str1, char *str2)
{
    int array[128];
    int i;
    i = 0;
    while (i < 128)
    {
        array[i] = 0;
        i++;
    } //创建一个有128格的array，因为所有字符最多128个可能性。给array中的每个值赋值0
    i = 0;
    while (str2[i])
    {
        array[(int)str2[i]] = 1;  //把str2[i]对应的字符‘x'转换为int,把对应这个int位置上的array的值变为1
        i++;
    }
    i = 0;
    while (str1[i])
    {
        if (array[(int)str1[i]] == 1) //首先看这个值有没有在str2中，有的话就显示出来，然后把对应格改成2，这样下次遇到的话就不会被显示出来了
        {
            write(1, &str1[i], 1);
            array[(int)str1[i]] = 2;  //已经显示过的，不再显示
        }
        i++;
    }
}
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        inter(argv[1], argv[2]);
    }
    write(1, "\n", 1);
    return (0);
}
