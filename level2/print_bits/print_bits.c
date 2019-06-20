/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:38:17 by yijhuang          #+#    #+#             */
/*   Updated: 2019/05/28 22:05:28 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 128;
    int len = 8;
	while (len-- > 0)
	{
		if ((octet & i) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i = i >> 1;
	}
}
