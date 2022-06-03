/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:21:57 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/14 14:15:13 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*rra(t_list *a, char *str)
{
	t_list	*tmp;

	if (a == NULL)
		return (NULL);
	else
	{
		tmp = a;
		while (tmp->next != a)
			tmp = tmp->next;
		a = tmp;
	}
	if (str)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	return (a);
}

void	rr(t_list **a, t_list **b, char *str)
{
	*a = ra(*a, str);
	*b = ra(*b, NULL);
	return ;
}

void	rrr(t_list **a, t_list **b, char *str)
{
	*a = rra(*a, str);
	*b = rra(*b, NULL);
	return ;
}

void	ss(t_list **a, t_list **b, char *str)
{
	*a = sa(*a, str);
	*b = sa(*b, NULL);
	return ;
}
