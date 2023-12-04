/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:26:46 by jjin              #+#    #+#             */
/*   Updated: 2022/11/15 22:28:53 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define SA 4
# define SB 5
# define RRA 6
# define RRB 7

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				rank;
	int				val;
}t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		len;
}t_stack;

int		ft_isdigit(int a);
int		ft_strlen(const char *str);

void	ft_exit(char *error);
void	check_input(int argc, char **argv);
void	normalize(t_stack *a);

void	operation(t_stack *a, t_stack *b, int command);
void	push(t_stack *from, t_stack *to);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);

void	push_front(t_stack *s, t_node *new);
void	push_rear(t_stack *s, t_node *new);
t_node	*pop_front(t_stack *s);
t_node	*pop_rear(t_stack *s);
void	printf_command(int command);

void	init(t_stack *a, t_stack *b, int argc, char **argv);
void	init_s(t_stack *s);
void	push_all_to_a(t_stack *a, int argc, char **argv);
void	push_new(t_stack *a, int num);

void	do_algorithm(t_stack *a, t_stack *b);
void	len_any_sort(t_stack *a, t_stack *b);
void	make_sand_clock(t_stack *a, t_stack *b);
void	sort_b_to_a(t_stack *a, t_stack *b);

void	len_three_sort(t_stack *a);
void	len_four_sort(t_stack *a, t_stack *b);
void	len_five_sort(t_stack *a, t_stack *b);

int		cnt_from_top(t_stack *a, int max_rank);
int		cnt_from_bot(t_stack *a, int max_rank);
void	rotate_max_rank_to_top(t_stack *s, int max_rank, int command);
int		is_sorted(t_stack *s);

#endif