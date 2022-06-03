/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:01 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/14 14:49:04 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sorted_increase(t_list *a)
{
	t_list	*tmp_list;
	int		tmp_data;

	tmp_list = a;
	while (tmp_list->next != a)
	{
		tmp_data = tmp_list->data;
		tmp_list = tmp_list->next;
		if (tmp_list->data <= tmp_data)
			return (0);
	}
	return (1);
}

static int	find_repeats(int **res, t_list **a)
{
	int	i;
	int	j;

	i = 0;
	while (i < list_length(*a))
	{
		j = 0;
		while (j < i)
			if ((*res)[i] == (*res)[j++])
				return (1);
		i++;
	}
	return (0);
}

int	repeat(t_list *a)
{
	t_list	*tmp;
	int		i;
	int		*res;
	int		repeats;

	res = malloc(list_length(a) * sizeof(int));
	if (!res)
		write_exit();
	i = 0;
	tmp = a;
	while (i < list_length(a))
	{
		res[i++] = tmp->data;
		tmp = tmp->next;
	}
	repeats = find_repeats(&res, &a);
	free(res);
	return (repeats);
}

int	list_length(t_list	*a)
{
	int		length;
	t_list	*tmp;

	length = 0;
	if (a == NULL)
		return (length);
	tmp = a;
	while (tmp->next != a)
	{
		tmp = tmp->next;
		length++;
	}
	length++;
	return (length);
}
