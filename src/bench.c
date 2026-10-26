/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-l <jmarin-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:14:58 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/26 17:00:37 by jmarin-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(t_config *cfg)
{
	int	scaled;
	int	int_part;
	int	dec_part;

	if (!cfg)
		return ;
	scaled = cfg->disorder * 10000;
	int_part = scaled / 100;
	dec_part = scaled % 100;
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

void	print_strategy(t_config *cfg)
{
	if (cfg->strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O(n2)\n", 2);
	else if (cfg->strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n/n)\n", 2);
	else if (cfg->strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (cfg->strategy == STRAT_ADAPTIVE)
		ft_putstr_fd("Adaptative / O(n/n)\n", 2);
}

void	print_bench(t_config *cfg)
{
	if (!cfg)
		return ;
	ft_putstr_fd("[bench]	disorder:	", 2);
	print_disorder(cfg);
	ft_putstr_fd("[bench]	strategy:	", 2);
	print_strategy(cfg);
	ft_putstr_fd("[bench]	total_ops:	", 2);
	ft_putnbr_fd(cfg->ops.total, 2);
	ft_putstr_fd("\n", 2);
}
