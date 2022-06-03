/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:18:15 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/15 11:22:33 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_min_move_rr_rarb(t_list **a, t_list **b, t_list **tmp)
{
	int	i;

	if ((*tmp)->ra >= (*tmp)->rb)
	{
		i = 0;
		while (i++ < (*tmp)->rb)
			rr(b, a, "rr");
		i = 0;
		while (i++ < ((*tmp)->ra - (*tmp)->rb))
			*a = ra(*a, "ra");
	}
	else if ((*tmp)->ra < (*tmp)->rb)
	{
		i = 0;
		while (i++ < (*tmp)->ra)
			rr(b, a, "rr");
		i = 0;
		while (i++ < ((*tmp)->rb - (*tmp)->ra))
			*b = ra(*b, "rb");
	}
	*a = pa(a, b, "pa");
	return ;
}

void	if_min_move_rrr_rrarrb(t_list **a, t_list **b, t_list **tmp)
{
	int	i;

	if ((*tmp)->rra >= (*tmp)->rrb)
	{
		i = 0;
		while (i++ < (*tmp)->rrb)
			rrr(b, a, "rrr");
		i = 0;
		while (i++ < ((*tmp)->rra - (*tmp)->rrb))
			*a = rra(*a, "rra");
	}
	else if ((*tmp)->rra < (*tmp)->rrb)
	{
		i = 0;
		while (i++ < (*tmp)->rra)
			rrr(b, a, "rrr");
		i = 0;
		while (i++ < ((*tmp)->rrb - (*tmp)->rra))
			*b = rra(*b, "rrb");
	}
	*a = pa(a, b, "pa");
	return ;
}

void	step_choice(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		min_min;
	int		min_move;

	calc_min_move(b, &min_min, &min_move);
	tmp = *b;
	while (tmp->min != min_min)
		tmp = tmp->next;
	if (min_move == 0)
		if_min_move_ra_rb(a, b, &tmp);
	else if (min_move == 1)
		if_min_move_rra_rb(a, b, &tmp);
	else if (min_move == 2)
		if_min_move_ra_rrb(a, b, &tmp);
	else if (min_move == 3)
		if_min_move_rra_rrb(a, b, &tmp);
	else if (min_move == 4)
		if_min_move_rr_rarb(a, b, &tmp);
	else if (min_move == 5)
		if_min_move_rrr_rrarrb(a, b, &tmp);
	return ;
}

void	write_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	array_handling(t_vars **vars, t_list **a)
{
	(*vars)->arr_size = find_arr_size(*a);
	create_arr(*a, vars);
	(*vars)->arr_sorted = quicksort((*vars)->arr, 0, (*vars)->arr_size);
	(*vars)->min = (*vars)->arr_sorted[0];
	(*vars)->max = (*vars)->arr_sorted[(*vars)->arr_size - 1];
	(*vars)->med = (*vars)->arr_sorted[(*vars)->arr_size / 2];
	return ;
}
