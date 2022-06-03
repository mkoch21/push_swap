/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:11:38 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/14 14:14:57 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*sa(t_list *a, char *str)
{
	int		tmp1;
	int		tmp2;
	t_list	*tmp_node;

	if ((a == NULL) || (a->next == a))
		return (a);
	else
	{
		tmp_node = a;
		tmp1 = tmp_node->data;
		tmp_node = tmp_node->next;
		tmp2 = tmp_node->data;
		tmp_node->data = tmp1;
		a->data = tmp2;
	}
	if (str)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	return (a);
}

static void	pa_part2(t_list **from, t_list **tmp2, t_list **tmp3)
{
	if (*from == (*from)->next)
	{
		free(*from);
		*from = NULL;
	}
	else
	{
		*tmp3 = *from;
		*from = (*from)->next;
		free(*tmp3);
		(*tmp2)->next = *from;
	}
	return ;
}

static void	pa_part3(t_list **to, t_list **to_new, t_list **tmp1)
{
	if (*to == NULL)
		(*to_new)->next = (*to_new);
	else
	{
		*tmp1 = *to;
		while ((*tmp1)->next != *to)
			*tmp1 = (*tmp1)->next;
		(*tmp1)->next = *to_new;
		(*to_new)->next = *to;
	}
	return ;
}

t_list	*pa(t_list **to, t_list **from, char *str)
{
	t_list	*to_new;
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (*from == NULL)
		return (*to);
	else
	{
		tmp2 = *from;
		while (tmp2->next != *from)
			tmp2 = tmp2->next;
		to_new = (t_list *)malloc(sizeof(t_list));
		if (!to_new)
			write_exit();
		to_new->data = (*from)->data;
		pa_part2 (from, &tmp2, &tmp3);
		pa_part3 (to, &to_new, &tmp1);
	}
	if (str)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	return (to_new);
}

t_list	*ra(t_list *a, char *str)
{
	if (a == NULL)
		return (NULL);
	else
		a = a->next;
	if (str)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	return (a);
}
