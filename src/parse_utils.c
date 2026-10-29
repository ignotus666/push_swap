/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:52:19 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/29 16:21:52 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_number_arg(char *arg, t_stack *a)
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

int	process_tokens(char **tokens, t_stack *a)
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
