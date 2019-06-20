/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:25:32 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 12:25:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int hcf;
	unsigned int lcm;
	unsigned int i;
	unsigned int min;

	i = 1;
	if(!a || !b)
		return (0);
	if (a <= b)
		min = a;
	else
		min = b;
	while(i <= min)
	{
		if (a % i == 0 && b % i == 0)
			hcf = i;
		i++;
	}
	lcm = (a * b) / hcf;
	return (lcm);
}
