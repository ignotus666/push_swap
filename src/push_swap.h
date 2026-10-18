/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:04:36 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/18 22:30:00 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

/* Stack utilities */
void	stack_init(t_stack *stack);
t_node	*create_node(int num);
int		stack_append(t_stack *stack, int num);
int		has_duplicate(t_stack *stack, int num);
void	free_stack(t_stack *stack);

/* String & char utilities */
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **words);

/* Parsing utilities */
long	ft_atol(const char *nptr, int *error);
int		is_valid_syntax(char *nums);
int		parse_flag(char *arg, t_config *cfg);
int		parse_args(int argc, char **argv, t_stack *a, t_config *cfg);

#endif