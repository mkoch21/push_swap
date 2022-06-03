/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:30:55 by mkoch             #+#    #+#             */
/*   Updated: 2022/03/21 11:42:11 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define  PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"
# include "get_next_line.h"

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

void	ss(t_list **a, t_list **b, char *str);
void	rr(t_list **a, t_list **b, char *str);
void	rrr(t_list **a, t_list **b, char *str);
void	correct_input(char	*str);
void	free_list(t_list *a);
void	write_exit(void);
void	*ft_free(char **res);
int		ft_atoi_new(const char *str);
int		sorted_increase(t_list *a);
int		repeat(t_list *a);
int		list_length(t_list	*a);
int		check_digits(char *str);
char	*get_next_line(int fd);
char	*ft_strdup_n(char *s1, int plus_n);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
t_list	*sa(t_list *a, char *str);
t_list	*pa(t_list **to, t_list **from, char *str);
t_list	*ra(t_list *a, char *str);
t_list	*rra(t_list *a, char *str);
t_list	*input_handling(int argc, char **argv);
t_list	*list_init(int length, int *res);
t_list	*add_to_list(int length, t_list *a, int *res_int);
size_t	ft_strlen_gnl(const char *s);

#endif
