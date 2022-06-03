/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:30:55 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/21 11:41:13 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_list
{
	int				data;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	int				steps;
	int				min;
	int				move;
	struct s_list	*next;
}	t_list;

typedef struct s_vars
{
	int		*arr;
	int		*arr_sorted;
	int		arr_size;
	int		med;
	int		min;
	int		max;
}	t_vars;

void	print_list(t_list *a);

void	ss(t_list **a, t_list **b, char *str);
void	rr(t_list **a, t_list **b, char *str);
void	rrr(t_list **a, t_list **b, char *str);
void	create_arr(t_list	*a, t_vars **vars);
void	*ft_free(char **res);
void	check_sorted_repeat(t_list **a);
void	correct_input(char	*str);
void	number_rb_rrb(t_list **a);
void	number_ra_rra(t_list **a, t_list **b);
void	number_rr(t_list **b);
void	number_rrr(t_list **b);
void	calc_min_move(t_list **b, int *min_min, int *min_move);
void	if_min_move_ra_rb(t_list **a, t_list **b, t_list **tmp);
void	if_min_move_rra_rb(t_list **a, t_list **b, t_list **tmp);
void	if_min_move_ra_rrb(t_list **a, t_list **b, t_list **tmp);
void	if_min_move_rra_rrb(t_list **a, t_list **b, t_list **tmp);
void	if_min_move_rr_rarb(t_list **a, t_list **b, t_list **tmp);
void	if_min_move_rrr_rrarrb(t_list **a, t_list **b, t_list **tmp);
void	step_choice(t_list **a, t_list **b);
void	presort(t_list **a, t_list **b, t_vars **vars);
void	mono_sort_3(t_list **a, int min);
void	main_sort(t_list **a, t_list **b, t_vars **vars);
void	final_sort(t_list **a, t_vars **vars);
void	array_handling(t_vars **vars, t_list **a);
void	min_steps(t_list **b);
void	write_exit(void);
void	free_list(t_list *a);
int		ft_atoi_new(const char *str);
int		find_arr_size(t_list	*a);
int		sorted_increase(t_list *a);
int		repeat(t_list *a);
int		*quicksort(int *arr, int low, int high);
int		list_length(t_list	*a);
int		check_digits(char *str);
t_list	*sa(t_list *a, char *str);
t_list	*pa(t_list **to, t_list **from, char *str);
t_list	*ra(t_list *a, char *str);
t_list	*rra(t_list *a, char *str);
t_list	*input_handling(int argc, char **argv);
t_list	*list_init(int length, int *res);
t_list	*add_to_list(int length, t_list *a, int *res_int);

#endif
