/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:48:31 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/18 00:23:16 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};  //建立一个只有一个int的链表，实际考试中不用写

static void		split(t_list *head, t_list **a, t_list **b)
{
	t_list	*slow;
	t_list	*fast;

	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
	return ;
}

static t_list	*merge_sorted(t_list *a, t_list *b, int (*cmp)(int, int))
{
	t_list	*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if ((*cmp)(a->data, b->data))
	{
		result = a;
		result->next = merge_sorted(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = merge_sorted(a, b->next, cmp);
	}
	return (result);
}


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list	*head;
	t_list	*a;
	t_list	*b;

	head = lst; //把头指针接到输入的lst上
	if (!head || !head->next) //如果输入的list不存在（指向null)或者next指向null(最后一个)
		return (NULL);
	split(head, &a, &b);
	sort_list(a, cmp);
	sort_list(b, cmp);
	lst = merge_sorted(a, b, cmp);
	return (lst);

}

