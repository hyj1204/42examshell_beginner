/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:48:12 by yijhuang          #+#    #+#             */
/*   Updated: 2019/02/25 13:48:28 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_char(char c)
{
		write(1, &c, 1);
}

char epur_str(char *str)
{
	int i;
  int space_status; //1表示在空格的状态，0表示在

	i = 0;
  space_status = 0;
  while (str[i] && (str[i] == '\t' || str[i] == ' '))
    i++;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == ' ')
    {
      space_status = 1;
      i++;
    }
		while (str[i] && str[i] != '\t' && str[i] != ' ')
    {
      if (space_status == 1)
      {
        put_char(' ');
        space_status = 0;
      }
      put_char(str[i]);
      i++;
    }
	}
	return (*str);
}

int main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		epur_str(av[1]);
    write(1, "\n", 1);
	}
	return (0);
}
