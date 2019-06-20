/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:43 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/18 12:43:00 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list   //定义结构体类型名s_list
{
    int num;
    struct s_list *next;
}   t_list;  //定义结构体变量t_list

int		cmp(int a, int b)
{
		return (a <= b);
}

/////////////////
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
t_list    *sort_list(t_list* lst, int (*cmp)(int, int)) //int (*cmp)(int, int) 的意思是把一个function作为输入参数放进去。
{
    t_list *head;
    t_list *p;

    head = lst;
    while (lst) //当当前链表节点存在的时候（一个个看每个节点的开头的地址）
    {
        p = lst->next; //每一个节点都有next，所以通过下一个节点存不存在来判断后面有没有值了。
        while (p) //当后面有值的时候
        {
            if (!(*cmp)(lst->num, p->num)) //看前后两个链表里的数据是否是正确的排序，如果不是的话（！0），就执行后面的语句
            {
                swap(&lst->num, &p->num);//交换这两个的位置，注意是要把这两个数的地址上的数交换,所以输入是这两个数的地址
            }
            p = p->next;//然后再比较后面一个数，注意是每一个节点都和后面的所有节点比较，得到最小或者最大的数放在最前面。
        }//当当前节点和后面的所有节点都比较过之后，把当前节点以移到后一个，和它后面的所有节点进行比较
        lst = lst->next;
    }
    return (lst);
}

//////////////////////

#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
	t_list *l;
	int		i;
	t_list	*t;
	t_list	*b;

	i = 50;
	l = malloc(sizeof(t_list));
	t = l;
	b = l;
	while (i)
	{
		l->num = i % 3;
		l->next = malloc(sizeof(t_list));
		l = l->next;
		--i;
	}
	l->num = 1000;
	l->next = NULL;
	while (t)
	{
		printf("%d ", t->num);
		t = t->next;
		++i;
	}
	b = sort_list(b, cmp);
	while (b)
	{
		printf("%d ", b->num);
		b = b->next;
		++i;
	}
    return (0);
}