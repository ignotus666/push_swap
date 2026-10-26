/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:04:36 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/26 10:53:41 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_tokens(char **tokens, t_stack *a)
{
	int		j;
	int		error;
	long	num;

	j = 0;
	while (tokens[j])
	{
		error = 0;
		if (!is_valid_syntax(tokens[j]))
			return (0);
		num = ft_atol(tokens[j], &error);
		if (error || has_duplicate(a, (int)num))
			return (0);
		if (!stack_append(a, (int)num))
			return (0);
		j++;
	}
	return (1);
}

static int	parse_number_arg(char *arg, t_stack *a)
{
	char	**tokens;

	if (!arg || arg[0] == '\0')
		return (0);
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	if (!tokens[0])
	{
		ft_free_split(tokens);
		return (0);
	}
	if (!process_tokens(tokens, a))
	{
		ft_free_split(tokens);
		return (0);
	}
	ft_free_split(tokens);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a, t_config *cfg)
{
	int	i;
	int	flag_status;

	i = 1;
	while (i < argc)
	{
		flag_status = parse_flag(argv[i], cfg);
		if (flag_status == -1)
			return (0);
		if (flag_status == 0)
		{
			if (!parse_number_arg(argv[i], a))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	run_strategy(t_stack *a, t_stack *b, t_config *cfg)
{
	if (cfg->strategy == STRAT_SIMPLE)
		alg_simple(a, b, cfg);
	else if (cfg->strategy == STRAT_MEDIUM)
		alg_medium(a, b, cfg);
	/*else if (cfg->strategy == STRAT_COMPLEX)
		alg_complex(a, b, cfg);
	else
		alg_adaptive(a, b, cfg);*/
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	cfg;

	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	config_init(&cfg);
	if (!parse_args(argc, argv, &a, &cfg))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&a);
		return (1);
	}
	cfg.disorder = compute_disorder(&a);
	if (cfg.disorder == 0.0f)
	{
		free_stack(&a);
		return (0);
	}
	run_strategy(&a, &b, &cfg);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
