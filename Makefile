# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:22:46 by mkoch             #+#    #+#              #
#    Updated: 2022/03/14 14:55:31 by mkoch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = src/libftpushswap.a
NAME_B = src_bonus/libftpushswapbonus.a

SRCS = src/rules.c src/rules2.c src/move.c src/move2.c src/sort.c src/calc_rules.c \
src/calc_steps.c src/input.c src/check_input.c src/lists.c src/quicksort.c
PS = src/push_swap.c

SRCS_B = src_bonus/get_next_line.c src_bonus/get_next_line_utils.c \
 src_bonus/rules_bonus.c src_bonus/rules2_bonus.c src_bonus/calc_steps_bonus.c \
 src_bonus/input_bonus.c src_bonus/check_input_bonus.c src_bonus/lists_bonus.c
PS_B = src_bonus/push_swap_bonus.c

HEADER = src/push_swap.h
HEADER_B = src_bonus/push_swap_bonus.h

LIBFT = libft/libft.a

OBJ = $(SRCS:%.c=%.o)
OBJ_B = $(SRCS_B:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME) push_swap $(HEADER)

$(NAME): $(OBJ) $(PS)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $?

src/%.o : src/%.c $(HEADER) $(PS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

push_swap: $(PS) Makefile 
	$(CC) $(CFLAGS) $(PS) -c -o src/push_swap.o
	$(CC) $(CFLAGS) $(NAME) src/push_swap.o -o push_swap

bonus: $(NAME_B) checker $(HEADER_B)

$(NAME_B): $(OBJ_B) $(PS_B)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME_B)
	ar rcs $(NAME_B) $?

src_bonus/%.o : src_bonus/%.c $(HEADER_B) $(PS_B) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

checker: $(PS_B) Makefile 
	$(CC) $(CFLAGS) $(PS_B) -c -o src_bonus/push_swap_bonus.o
	$(CC) $(CFLAGS) $(NAME_B) src_bonus/push_swap_bonus.o -o checker


clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(OBJ_B) src/push_swap.o src_bonus/push_swap_bonus.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(NAME_B) push_swap checker

re: fclean all

.PHONY: all clean fclean re
