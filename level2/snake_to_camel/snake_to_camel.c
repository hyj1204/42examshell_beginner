/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:27:30 by yijhuang          #+#    #+#             */
/*   Updated: 2019/06/17 13:48:35 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_pc(char c)
{
    write(1, &c, 1);
}

void snake(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '_')
        {
            i++;
            if (str[i] && str[i] >= 'a' && str[i] <= 'z')
            {
                ft_pc(str[i] - 'a' + 'A');
            }
        }
        else
            ft_pc(str[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        snake(av[1]);
    ft_pc('\n');
    return 0;
}