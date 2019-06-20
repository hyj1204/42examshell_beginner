/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 12:12:57 by yijhuang          #+#    #+#             */
/*   Updated: 2019/01/27 12:29:09 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	i++;
	char tmp[i];
	i = 0;
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	i = 0;
	while (j)
	{
		str[i] = tmp[j - 1];
		j--;
		i++;
	}
	return str;
}
