/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:16:51 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 10:59:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
	if (size > 0)
	{
		int i;
		int max;
		int max_i;
		int tmp;
		
		while (size > 0)
		{
			i = size - 1;
			max = tab[0];
			max_i = 0;
			tmp = 0;
			while (i > 0)
			{
				if (tab[i] >= max)
				{
					max = tab[i];
					max_i = i;
				}
				i--;
			}
			tmp = tab[size - 1];
			tab[size - 1] = max;
			tab[max_i] = tmp;
			size--;
		}
	}
}
