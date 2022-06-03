/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:38 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/15 12:19:11 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	list_init2(t_list **next, t_list **first, int length, int *res)
{
	int		i;

	i = 1;
	*next = (*first)->next;
	while (i < length)
	{
		(*next)->data = res[i];
		if (i == (length - 1))
			(*next)->next = *first;
		else
		{
			(*next)->next = (t_list *)malloc(sizeof(t_list));
			if (!(*next)->next)
				write_exit();
			*next = (*next)->next;
		}
		i++;
	}
}

t_list	*list_init(int length, int *res)
{
	t_list	*first;
	t_list	*next;

	first = (t_list *)malloc(sizeof(t_list));
	if (!first)
		write_exit();
	first->data = res[0];
	if (length == 1)
		first->next = first;
	else
	{
		first->next = (t_list *)malloc(sizeof(t_list));
		if (!first->next)
			write_exit();
		list_init2(&next, &first, length, res);
	}
	return (first);
}

t_list	*add_to_list(int length, t_list *a, int *res_int)
{
	t_list	*tmp;
	int		i;

	tmp = a;
	while (tmp->next != a)
		tmp = tmp->next;
	i = 0;
	while (i < length)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		if (!tmp->next)
			exit(1);
		tmp = tmp->next;
		tmp->data = res_int[i];
		i++;
	}
	tmp->next = a;
	return (a);
}

void	free_list(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp_begin;

	if (a == NULL)
		return ;
	tmp = a;
	tmp_begin = a;
	while (tmp->next != tmp_begin)
	{
		a = tmp->next;
		free(tmp);
		tmp = a;
	}
	free(tmp);
	return ;
}

int	find_arr_size(t_list	*a)
{
	int		size;
	t_list	*tmp;

	tmp = a;
	size = 0;
	while (tmp->next != a)
	{
		size++;
		tmp = tmp->next;
	}
	size++;
	return (size);
}
