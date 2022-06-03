/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_steps_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:36:17 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/21 11:42:07 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
