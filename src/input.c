/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:30:53 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/21 11:41:22 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_new(const char *str)
{
	int					i;
	int					neg;
	unsigned long long	nb;

	neg = 1;
	i = 0;
	nb = 0;
	while ((str[i] == ' ') || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
		neg = -1;
	if ((str[i] == '+') || (str[i] == '-') || str[i] == '0')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9') && (str[i] != '\0'))
		nb = nb * 10 + str[i++] - '0';
	if (((nb > 2147483647) && (neg == 1)) || ((neg == -1) && (nb > 2147483648)))
		write_exit();
	return (neg * (int)nb);
}

void	check_integer(char **res_str)
{
	int	i;
	int	j;
	int	num_digits;

	i = 0;
	while (res_str[i])
	{
		j = 0;
		num_digits = 0;
		while (res_str[i][j] == '0')
			j++;
		while (ft_isdigit(res_str[i][j]))
		{
			j++;
			num_digits++;
		}
		if (num_digits > 10)
			write_exit();
		i++;
	}
	return ;
}

static void	input_handling2(t_list **a, int	**res_int, char	***res_str)
{
	int	j;
	int	length;

	length = 0;
	while ((*res_str)[length])
		length++;
	*res_int = malloc(sizeof(int) * length);
	if (!(*res_int))
		write_exit();
	j = 0;
	while (j < length)
	{
		(*res_int)[j] = ft_atoi_new((*res_str)[j]);
		j++;
	}
	if (!(*a))
		*a = list_init(length, *res_int);
	else
		*a = add_to_list(length, *a, *res_int);
	return ;
}

t_list	*input_handling(int argc, char **argv)
{
	t_list	*a;
	int		i;
	int		*res_int;
	char	**res_str;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		correct_input(argv[i]);
		if (check_digits(argv[i]) == 0)
			write_exit();
		res_str = ft_split(argv[i], ' ');
		check_integer(res_str);
		input_handling2(&a, &res_int, &res_str);
		i++;
		free(res_int);
		ft_free(res_str);
	}
	return (a);
}

void	create_arr(t_list	*a, t_vars **vars)
{
	t_list	*tmp;
	int		i;

	(*vars)->arr = malloc(sizeof(int) * (*vars)->arr_size);
	if (!(*vars)->arr)
		write_exit();
	i = 0;
	tmp = a;
	while (i < (*vars)->arr_size)
	{
		(*vars)->arr[i++] = tmp->data;
		tmp = tmp->next;
	}
	return ;
}
