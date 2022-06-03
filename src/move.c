/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:15:47 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/11 14:17:48 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_min_move(t_list **b, int *min_min, int *min_move)
{
	t_list	*tmp;

	tmp = *b;
	*min_min = tmp->min;
	*min_move = tmp->move;
	while (tmp->next != *b)
	{
		if (tmp->min < *min_min)
		{
			*min_min = tmp->min;
			*min_move = tmp->move;
		}
		tmp = tmp->next;
	}
	if (tmp->min < *min_min)
	{
		*min_min = tmp->min;
		*min_move = tmp->move;
	}
	return ;
}

void	if_min_move_ra_rb(t_list **a, t_list **b, t_list **tmp)
{
	int	i;

	i = 0;
	while (i++ < (*tmp)->ra)
		*a = ra(*a, "ra");
	i = 0;
	while (i++ < (*tmp)->rb)
		*b = ra(*b, "rb");
	*a = pa(a, b, "pa");
	return ;
}

void	if_min_move_rra_rb(t_list **a, t_list **b, t_list **tmp)
{
	int	i;

	i = 0;
	while (i++ < (*tmp)->rra)
		*a = rra(*a, "rra");
	i = 0;
	while (i++ < (*tmp)->rb)
		*b = ra(*b, "rb");
	*a = pa(a, b, "pa");
	return ;
}

void	if_min_move_ra_rrb(t_list **a, t_list **b, t_list **tmp)
{
	int	i;

	i = 0;
	while (i++ < (*tmp)->ra)
		*a = ra(*a, "ra");
	i = 0;
	while (i++ < (*tmp)->rrb)
		*b = rra(*b, "rrb");
	*a = pa(a, b, "pa");
	return ;
}

void	if_min_move_rra_rrb(t_list **a, t_list **b, t_list **tmp)
{
	int	i;

	i = 0;
	while (i++ < (*tmp)->rra)
		*a = rra(*a, "rra");
	i = 0;
	while (i++ < (*tmp)->rrb)
		*b = rra(*b, "rrb");
	*a = pa(a, b, "pa");
	return ;
}
