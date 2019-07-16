/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:55:47 by yijhuang          #+#    #+#             */
/*   Updated: 2019/07/15 22:43:17 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.c"
#include <stdio.h>

int main (int ac, char **av)
{
    char **arr;
    int i;

    arr = ft_split(av[1]);
    i = 0;
    while (arr[i])
    {
        printf("element = %s\n", arr[i]);
        i++;
    }
    return 0;
}