/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:04:36 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/19 08:59:52 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_syntax(char *nums)
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

static int	check_duplicates(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_atol(nums[i], NULL) == ft_atol(nums[j], NULL))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_nums(char **nums)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	if (!nums || !nums[0])
		return (0);
	while (nums[i])
	{
		if (!is_valid_syntax(nums[i]))
			return (0);
		ft_atol(nums[i], &error);
		if (error == 1)
			return (0);
		i++;
	}
	if (!check_duplicates(nums))
		return (0);
	return (1);
}

t_stack	*create_stacks(char **nums)
{
	t_stack	*a;
	t_stack	*b;
}

int	main(int argc, char **argv)
{
	char	**nums;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = create_nums_str(argv);
	if (validate_nums(nums))
		create_stacks(nums);
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_split(nums);
		return (1);
	}
	return (0);
}
