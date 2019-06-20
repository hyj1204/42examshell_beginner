/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_print_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:12:20 by yijhuang          #+#    #+#             */
/*   Updated: 2019/05/28 22:05:16 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int main()
{
    unsigned char c;

    c = 2; //注意这里赋的值是机器码，不是字符‘2'
    printf("unsigned char 2 = %d\n", c);
    print_bits(c);
    return 0;
}