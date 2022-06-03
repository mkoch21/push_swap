/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:50:38 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/21 11:18:06 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_repeat(t_list **a)
{
	if (repeat(*a))
	{
		free_list(*a);
		write_exit();
	}
	return ;
}

int	list_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next != *a)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	apply_step(t_list **a, t_list **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		*a = sa(*a, NULL);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		*b = sa(*b, NULL);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, NULL);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		*a = pa(a, b, NULL);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		*b = pa(b, a, NULL);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		*a = rra(*a, NULL);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		*b = rra(*b, NULL);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, NULL);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		*a = ra(*a, NULL);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		*b = ra(*b, NULL);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, NULL);
	else
		write_exit();
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (argc == 1)
		exit(1);
	b = NULL;
	a = input_handling(argc, argv);
	check_repeat(&a);
	line = get_next_line(0);
	while (line != 0)
	{
		apply_step(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (list_sorted(&a) && (b == NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(a);
	return (0);
}
