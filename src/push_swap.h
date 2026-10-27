/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:04:36 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/26 16:57:43 by jmarin-l         ###   ########.fr       */
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
	STRAT_SIMPLE = 1,
	STRAT_MEDIUM = 2,
	STRAT_COMPLEX = 3
}	t_strategy;

typedef struct s_ops
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
	float		disorder;
	t_ops		ops;
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

/* Compute disorder utilities */
float	compute_disorder(t_stack *a);

/* Operations */
void	config_init(t_config *cfg);
void	op_sa(t_stack *a, t_config *cfg);
void	op_sb(t_stack *b, t_config *cfg);
void	op_ss(t_stack *a, t_stack *b, t_config *cfg);
void	op_pa(t_stack *a, t_stack *b, t_config *cfg);
void	op_pb(t_stack *a, t_stack *b, t_config *cfg);
void	op_ra(t_stack *a, t_config *cfg);
void	op_rb(t_stack *b, t_config *cfg);
void	op_rr(t_stack *a, t_stack *b, t_config *cfg);
void	op_rra(t_stack *a, t_config *cfg);
void	op_rrb(t_stack *b, t_config *cfg);
void	op_rrr(t_stack *a, t_stack *b, t_config *cfg);

/* Algortihm utils */
int		get_max(t_stack *s, int *index);

/* Algorithms */
void	alg_simple(t_stack *a, t_stack *b, t_config *cfg);
void	alg_medium(t_stack *a, t_stack *b, t_config *cfg);

/* Bench */
void	print_bench(t_config *cfg);

#endif