/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_check_mate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 10:17:13 by yijhuang          #+#    #+#             */
/*   Updated: 2019/02/24 12:22:51 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rook 车是可以直线移动。
//Queen 是可以直线移动+斜线移动。
//Bishops 主教（象）：斜线移动
//Pawns 兵：兵只能吃他斜上方一格的棋子。兵只能向前不能后退。

#include <stdlib.h>
#include <unistd.h>

int		check_mate(int ac, char **av)
{
	int		y = 0;
	int		x = 0;
	int		len = 0;
	int		b = 0;
	int		a = 0;
	char	**m;
	int		i = 0;

	while (ac-- > 1)  //计算一共有多少个输入。len=4
		len++;
	if (!(m = (char **)malloc(sizeof(char *) * (len + 1))))  //为什么是len +1？因为后面的代码中会判断k下面一行的值（pawns part），如果没有空间的话，系统就无法搜索了。
		return (0);
	y = 0;
	while (y < len)
	{
		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		x = 0;
		while (av[y + 1][x])  //对于每一个输入文件
		{
			m[y][x] = av[y + 1][x]; //把每一值放进malloc出来的空间里
			if (m[y][x] == 'K') //如果遇到k的话，就记录k在新的malloc里的坐标
			{
				a = x;
				b = y;
			}
			x++;
		}
		m[y][x] = '\0';//每一行最后一个放\0
		y++;
	}

	if (m[b + 1][a + 1] == 'P' || m[b + 1][a - 1] == 'P') //如果k在pawns的斜方面一格的位置，就会被吃掉
		return (1);
	// . . . . . . .
	// . . . . . . .
	// . . X . X . .
	// . . . P . . .
	// . . . . . . .
	// . . . . . . .
	// . . . . . . .
	while (i < len)
	{
		if (m[b][i] == 'Q' || m[i][a] == 'Q' || m[b][i] == 'R' || m[i][a] == 'R') //rook 车是可以直线移动。
			return (1);
	// . . . X . . .
	// . . . X . . .
	// . . . X . . .
	// X X X R X X X
	// . . . X . . .
	// . . . X . . .
	// . . . X . . .
		if (i < b)
		{
			if (i < a && (m[(b - 1) - i][(a - 1)- i] == 'B' || m[(b - 1) - i][(a - 1) - i] == 'Q') ) //在第二象限时（左上）
				return (1);
			if (a + i < len && (m[(b - 1) - i][(a + 1) + i] == 'B' || m[(b - 1) - i][(a + 1) + i] == 'Q'))//在第一象限时（右上）
				return (1);
		}
	// X . .| .| . . X
	// . X .| .| . X .
	// . . X| .| X . .
	// ---------------
	// . . .| B| . . .
	// ---------------
	// . . X| .| X . .
	// . X .| .| . X .
	// X . .| .| . . X
		if (b + i < len)
		{
			if (i < a && (m[(b + 1) + i][(a - 1) - i] == 'B' || m[(b + 1) + i][(a - 1) - i] == 'Q'))//在第三象限时（左下）
				return (1);
			if (a + i < len && (m[(b + 1) + i][(a + 1) + i] == 'B' || m[(b + 1) + i][(a + 1) + i] == 'Q' ))//在第四象限时（右下）
				return (1);
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)  //输入是多个字符串
{
	if (ac <= 1)
	 	write(1, "\n", 1);
	else
	{ 
		if (check_mate(ac, av)) //如果是多个输入并且check_mate返回1则显示成功。否则显示失败。
		write(1, "Success\n", 8);
	  	else
		write(1, "Fail\n", 5);
	}
	return (0);
}
