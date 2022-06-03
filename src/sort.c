/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:25:24 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/15 12:28:27 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	presort2(t_list **a, t_list **b, t_vars **vars, t_list **tmp)
{
	if ((*tmp)->data > (*vars)->med)
	{
		*tmp = (*tmp)->next;
		*b = pa(b, a, "pb");
		if ((*vars)->arr_size != 5)
			*b = ra(*b, "rb");
	}
	else
	{
		*tmp = (*tmp)->next;
		*b = pa(b, a, "pb");
	}
	return ;
}

void	presort(t_list **a, t_list **b, t_vars **vars)
{
	t_list	*tmp_a;
	t_list	*tmp;

	tmp_a = 0;
	tmp = *a;
	while ((list_length(*a) != 3))
	{
		if ((tmp->data != (*vars)->max) && (tmp->data != (*vars)->min))
			presort2(a, b, vars, &tmp);
		else
		{
			if (tmp_a == 0)
				tmp_a = tmp;
			tmp = tmp->next;
			*a = ra(*a, "ra");
		}
	}
	return ;
}

void	mono_sort_3(t_list **a, int min)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->data != min)
		tmp = tmp->next;
	if ((tmp->data > tmp->next->data) || ((tmp->data < tmp->next->data) && \
	(tmp->next->data > tmp->next->next->data)))
		*a = sa(*a, "sa");
	return ;
}

void	final_sort(t_list **a, t_vars **vars)
{
	t_list	*tmp;
	int		i;
	int		start;

	tmp = *a;
	i = 1;
	while (tmp->next != *a)
	{
		if (tmp->data > tmp->next->data)
			start = i;
		i++;
		tmp = tmp->next;
	}
	i = 0;
	if (start != 0)
	{
		if (start < ((*vars)->arr_size - start))
			while (i++ < start)
				*a = ra(*a, "ra");
		else
			while (i++ < ((*vars)->arr_size - start))
				*a = rra(*a, "rra");
	}
	return ;
}

void	main_sort(t_list **a, t_list **b, t_vars **vars)
{
	if ((*vars)->arr_size > 3)
		presort(a, b, vars);
	mono_sort_3(a, (*vars)->min);
	while (*b)
	{
		number_rb_rrb(b);
		number_ra_rra(a, b);
		number_rr(b);
		number_rrr(b);
		min_steps(b);
		step_choice(a, b);
	}
	final_sort(a, vars);
	return ;
}
