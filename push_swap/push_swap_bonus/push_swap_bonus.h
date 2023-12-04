/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:26:46 by jjin              #+#    #+#             */
/*   Updated: 2022/11/16 10:30:30 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define INT_MAX 2147483647

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

void		ft_exit(char *error);
void		check_input(int argc, char **argv);
void		normalize(t_stack *a);

void		checker(t_stack *a, t_stack *b);
void		parse_operation(t_stack *a, t_stack *b, char *s);
int			ft_strcmp(char *s, char *com);
int			is_sorted_two(t_stack *a, t_stack *b);
int			is_sorted(t_stack *s);

size_t		ft__strlen(const char *str);
void		*ft__memmove(void *dst, const void *src, size_t len);
size_t		ft__strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft__strdup(const char *s1);
char		*ft__strjoin(char *s1, char *s2);

int			check_new_line(char *buf);
char		*ft_read_line(int fd, char *backup);
char		*ft_get_line(char **str);
char		*get_next_line(int fd);

void		init(t_stack *a, t_stack *b, int argc, char **argv);
long long	ft_atoll(char *str);
void		init_s(t_stack *s);
void		push_all_to_a(t_stack *a, int argc, char **argv);
void		push_new(t_stack *a, int num);

int			ft_isdigit(int a);
int			ft_strlen(const char *str);

int			ft_strlen(const char *str);
void		check_input(int argc, char **argv);
void		normalize(t_stack *a);

void		push(t_stack *from, t_stack *to);
void		swap(t_stack *s);
void		rotate(t_stack *s);
void		reverse_rotate(t_stack *s);

void		swap_double(t_stack *a, t_stack *b);
void		rotate_double(t_stack *a, t_stack *b);
void		reverse_rotate_double(t_stack *a, t_stack *b);

void		push_front(t_stack *s, t_node *new);
void		push_rear(t_stack *s, t_node *new);
t_node		*pop_front(t_stack *s);
t_node		*pop_rear(t_stack *s);

#endif