/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:55 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/21 11:41:06 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_vars	*vars;

	if (argc == 1)
		exit(1);
	b = NULL;
	a = input_handling(argc, argv);
	check_sorted_repeat(&a);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		write_exit();
	array_handling(&vars, &a);
	main_sort(&a, &b, &vars);
	free(vars->arr_sorted);
	free(vars);
	free_list(a);
	free_list(b);
	return (0);
}
