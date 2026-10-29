/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:52:19 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/26 18:58:46 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr, int *error)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		if (num > (long)INT_MAX + 1)
			break ;
		nptr++;
	}
	if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
	{
		if (error)
			*error = 1;
	}
	return (sign * num);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_syntax(char *nums)
{
	int	i;

	i = 0;
	if (nums[i] == '+' || nums[i] == '-')
		i++;
	if (nums[i] == '\0')
		return (0);
	while (nums[i])
	{
		if (!ft_isdigit(nums[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_flag(char *arg, t_config *cfg)
{
	if (arg[0] != '-' || arg[1] != '-')
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		cfg->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		cfg->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		cfg->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptative", 11) == 0)
		cfg->strategy = STRAT_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		cfg->bench = 1;
	else
		return (-1);
	return (1);
}

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
