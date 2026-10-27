/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:14:58 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/27 19:45:06 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_config *cfg)
{
	int	scaled;
	int	int_part;
	int	dec_part;

	if (!cfg)
		return ;
	scaled = cfg->disorder * 10000;
	int_part = scaled / 100;
	dec_part = scaled % 100;
	ft_putstr_fd("[bench]	disorder:	", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putstr_fd(".", 2);
	if (dec_part < 10)
	{
		ft_putnbr_fd(0, 2);
		ft_putnbr_fd(dec_part, 2);
	}
	else
		ft_putnbr_fd(dec_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_config *cfg)
{
	ft_putstr_fd("[bench]	strategy:	", 2);
	if (cfg->strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O(n²)\n", 2);
	else if (cfg->strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (cfg->strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (cfg->strategy == STRAT_ADAPTIVE)
	{
		if (cfg->disorder < 0.2f)
			ft_putstr_fd("Adaptive / O(n)\n", 2);
		else if (cfg->disorder < 0.5f)
			ft_putstr_fd("Adaptive / O(n√n)\n", 2);
		else
			ft_putstr_fd("Adaptive / O(n log n)\n", 2);
	}
}

static void	print_total_ops(t_config *cfg)
{
	ft_putstr_fd("[bench]	total_ops:	", 2);
	ft_putnbr_fd(cfg->ops.total, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_ops(t_config *cfg)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(cfg->ops.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(cfg->ops.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(cfg->ops.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(cfg->ops.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(cfg->ops.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(cfg->ops.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(cfg->ops.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(cfg->ops.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(cfg->ops.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(cfg->ops.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(cfg->ops.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_config *cfg)
{
	if (!cfg)
		return ;
	print_disorder(cfg);
	print_strategy(cfg);
	print_total_ops(cfg);
	print_ops(cfg);
}
