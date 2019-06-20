/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:29:04 by exam              #+#    #+#             */
/*   Updated: 2019/03/13 21:55:27 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(const char *str, int str_base)
{
	int i;
	int num;
	int flag;

	i = 0;
	num = 0;
	flag = 1;
	if (str[i] == '-')
	{
		flag= -1;
		i++;
	}
	if (str_base > 10)
	{
		while (str[i])
		{
		if (str[i] >= 'A' && str[i] <= 'Z')
			num = str_base * num + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'z')
            num = str_base * num + (str[i] - 'a' + 10);
		else if (str[i] >= '0' && str[i] <= '9')
			num = str_base * num + (str[i] - '0');
		else
			break ;
		i++;
		}
	}
	else
	{
		while (str[i])
		{
		num = str_base * num + (str[i] - '0');
		i++;
		}
	}
	return (flag * num);
}
