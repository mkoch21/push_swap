/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:09 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/11 17:45:13 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_right(int *arr, int i, int j)
{
	int	tmp;

	while (i < j)
	{
		tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
		i++;
	}
	j--;
	return (j);
}

static int	move_left(int *arr, int i, int j)
{
	int	tmp;

	while (i > j)
	{
		tmp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = tmp;
		i--;
	}
	j++;
	return (j);
}

static int	split_arr(int *arr, int j, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((arr[i] > arr[j]) && (i < j))
		{
			j = move_right(arr, i, j);
			i--;
		}
		else if ((arr[i] <= arr[j]) && (i > j))
			j = move_left(arr, i, j);
		i++;
	}
	return (j);
}

int	*quicksort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = split_arr(arr, low, high);
		quicksort(arr, low, pivot);
		quicksort(arr, pivot + 1, high);
	}
	return (arr);
}
