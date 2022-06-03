/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:27:21 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/11 14:37:20 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_rb_rrb(t_list **a)
{
	int		length;
	t_list	*tmp;
	int		i;

	tmp = *a;
	tmp->rb = 0;
	tmp->rrb = 0;
	tmp = tmp->next;
	i = 1;
	length = list_length(*a);
	while (i < length)
	{
		tmp->rb = i;
		tmp->rrb = length - i;
		i++;
		tmp = tmp->next;
	}
	return ;
}

static void	for_each_b(t_list **a, t_list **tmp_b, int a_last, int length)
{
	t_list	*tmp_a;
	int		i;

	i = 0;
	tmp_a = *a;
	if ((a_last < (*tmp_b)->data) && ((*tmp_b)->data < tmp_a->data))
	{
		(*tmp_b)->ra = 0;
		(*tmp_b)->rra = 0;
	}
	else
	{
		while (!((tmp_a->data < (*tmp_b)->data)
				&& ((*tmp_b)->data < tmp_a->next->data)))
		{
			tmp_a = tmp_a->next;
			i++;
		}
		i++;
		(*tmp_b)->ra = i;
		(*tmp_b)->rra = length - i;
	}
	return ;
}

void	number_ra_rra(t_list **a, t_list **b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;
	int		length;
	int		a_last;

	tmp_b = *b;
	tmp_a = *a;
	length = list_length(*a);
	while (tmp_a->next != *a)
		tmp_a = tmp_a->next;
	a_last = tmp_a->data;
	while (tmp_b->next != *b)
	{
		for_each_b(a, &tmp_b, a_last, length);
		tmp_b = tmp_b->next;
	}
	for_each_b(a, &tmp_b, a_last, length);
	return ;
}

void	number_rr(t_list **b)
{
	t_list	*tmp_b;

	tmp_b = *b;
	while (tmp_b->next != *b)
	{
		if ((tmp_b->ra > 0) && (tmp_b->rb > 0) && (tmp_b->ra >= tmp_b->rb))
			tmp_b->rr = tmp_b->rb;
		else if ((tmp_b->ra > 0) && (tmp_b->rb > 0) && (tmp_b->ra < tmp_b->rb))
			tmp_b->rr = tmp_b->ra;
		else
			tmp_b->rr = 0;
		tmp_b = tmp_b->next;
	}
	if ((tmp_b->ra > 0) && (tmp_b->rb > 0) && (tmp_b->ra >= tmp_b->rb))
		tmp_b->rr = tmp_b->rb;
	else if ((tmp_b->ra > 0) && (tmp_b->rb > 0) && (tmp_b->ra < tmp_b->rb))
		tmp_b->rr = tmp_b->ra;
	else
		tmp_b->rr = 0;
	return ;
}

void	number_rrr(t_list **b)
{
	t_list	*tmp_b;

	tmp_b = *b;
	while (tmp_b->next != *b)
	{
		if ((tmp_b->rra > 0) && (tmp_b->rrb > 0) && (tmp_b->rra >= tmp_b->rrb))
			tmp_b->rrr = tmp_b->rrb;
		else if ((tmp_b->rra > 0) && (tmp_b->rrb > 0)
			&& (tmp_b->rra < tmp_b->rrb))
			tmp_b->rrr = tmp_b->rra;
		else
			tmp_b->rrr = 0;
		tmp_b = tmp_b->next;
	}
	if ((tmp_b->rra > 0) && (tmp_b->rrb > 0) && (tmp_b->rra >= tmp_b->rrb))
		tmp_b->rrr = tmp_b->rrb;
	else if ((tmp_b->rra > 0) && (tmp_b->rrb > 0) && (tmp_b->rra < tmp_b->rrb))
		tmp_b->rrr = tmp_b->rra;
	else
		tmp_b->rrr = 0;
	return ;
}
