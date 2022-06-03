/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:36:17 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/12 20:20:35 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_number_of_steps(int (*sum)[6], t_list	**tmp)
{
	(*sum)[0] = (*tmp)->ra + (*tmp)->rb;
	(*sum)[1] = (*tmp)->rra + (*tmp)->rb;
	(*sum)[2] = (*tmp)->ra + (*tmp)->rrb;
	(*sum)[3] = (*tmp)->rra + (*tmp)->rrb;
	if (((*tmp)->rr != 0) && ((*tmp)->ra >= (*tmp)->rb))
		(*sum)[4] = (*tmp)->ra;
	else if (((*tmp)->rr != 0) && ((*tmp)->ra < (*tmp)->rb))
		(*sum)[4] = (*tmp)->rb;
	else
		(*sum)[4] = 0;
	if (((*tmp)->rrr != 0) && ((*tmp)->rra >= (*tmp)->rrb))
		(*sum)[5] = (*tmp)->rra;
	else if (((*tmp)->rrr != 0) && ((*tmp)->rra < (*tmp)->rrb))
		(*sum)[5] = (*tmp)->rrb;
	else
		(*sum)[5] = 0;
	return ;
}

static void	calc_min_number_of_steps(int (*sum)[6], t_list **tmp)
{
	int		imin;
	int		i;

	imin = 0;
	i = 1;
	while (i < 4)
	{
		if (((*sum)[i] < (*sum)[imin]))
			imin = i;
		i++;
	}
	if (((*sum)[4] < (*sum)[imin]) && ((*sum)[4] != 0))
		imin = 4;
	if (((*sum)[5] < (*sum)[imin]) && ((*sum)[5] != 0))
		imin = 5;
	(*tmp)->move = imin;
	(*tmp)->min = (*sum)[imin];
	return ;
}

void	min_steps(t_list **b)
{
	t_list	*tmp;
	int		sum[6];

	tmp = *b;
	while (tmp->next != *b)
	{
		calc_number_of_steps(&sum, &tmp);
		calc_min_number_of_steps(&sum, &tmp);
		tmp = tmp->next;
	}
	calc_number_of_steps(&sum, &tmp);
	calc_min_number_of_steps(&sum, &tmp);
	return ;
}

void	correct_input(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && (str[i] != ' '))
		{
			if (((str[i] == '-') || (str[i] == '+')) && ft_isdigit(str[i + 1]))
			{
				if (i > 0)
					if (str[i - 1] != ' ')
						write_exit();
			}
			else
				write_exit();
		}
		i++;
	}
	return ;
}

void	*ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}
