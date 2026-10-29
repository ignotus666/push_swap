/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:04:36 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/29 16:21:37 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	config_init(t_config *cfg)
{
	cfg->strategy = STRAT_ADAPTIVE;
	cfg->bench = 0;
	cfg->ops.total = 0;
	cfg->ops.sa = 0;
	cfg->ops.sb = 0;
	cfg->ops.ss = 0;
	cfg->ops.pa = 0;
	cfg->ops.pb = 0;
	cfg->ops.ra = 0;
	cfg->ops.rb = 0;
	cfg->ops.rr = 0;
	cfg->ops.rra = 0;
	cfg->ops.rrb = 0;
	cfg->ops.rrr = 0;
}

static int	parse_flag(char *arg, t_config *cfg)
{
	if (arg[0] != '-' || arg[1] != '-')
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		cfg->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		cfg->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		cfg->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		cfg->strategy = STRAT_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		cfg->bench = 1;
	else
		return (-1);
	return (1);
}

static int	parse_args(int argc, char **argv, t_stack *a, t_config *cfg)
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
	else if (cfg->strategy == STRAT_COMPLEX)
		alg_complex(a, b, cfg);
	else
		alg_adaptive(a, b, cfg);
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
	if (cfg.disorder != 0.0f)
		run_strategy(&a, &b, &cfg);
	if (cfg.bench)
		print_bench(&cfg);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
