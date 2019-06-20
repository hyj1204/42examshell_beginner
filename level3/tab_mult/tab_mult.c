/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:52:27 by yijhuang          #+#    #+#             */
/*   Updated: 2019/06/17 16:06:38 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_pc(char c)
{
    write(1, &c, 1);
}

void ft_pstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_pc(str[i]);
        i++;
    }
}

int atoi(char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    if (str[i] == '+')
        i++;
    if (str[i] == '-')
        return 0;
    while (str[i])
    {
        num = num * 10 + (int)str[i] - '0';
        i++;
    }
    return num;
}

void pitoa(int pnum)
{
    int len;
    int num;

    len = 0;
    num = pnum;
    if (num < 10)
        ft_pc(num + '0');
    else
    {
        while (num > 0)
        {
            len++;
            num = num / 10;
        }
        char str[len + 1];
        str[len] = '\0';
        while(len > 0)
        {
            str[len - 1] = (pnum % 10) + '0';
            pnum = pnum / 10;
            len--;  
        }
        len = 0;
        while (str[len])
        {
            ft_pc(str[len]);
            len++;
        }
    }
}

void mult(char *str)
{
    int num;
    int i;

    num = atoi(str);
    i = 1;
    while (i <= 9)
    {
        ft_pc('0' + i);
        ft_pstr(" x ");
        pitoa(num);
        ft_pstr(" = ");
        pitoa((i * num));
        ft_pc('\n');
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        mult(av[1]);
    else
        ft_pc('\n');
}
