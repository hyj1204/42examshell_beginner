/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:59:30 by yijhuang          #+#    #+#             */
/*   Updated: 2019/05/28 22:22:30 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char result = 0;
	unsigned int  len = 8;

	while (len > 0)
	{
		result = (result << 1) | (octet & 1); 
        octet = octet >> 1;
		len--;
	}
	return (result);
}