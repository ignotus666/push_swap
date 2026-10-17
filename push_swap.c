/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-l <jmarin-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:04:36 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/16 15:04:46 by jmarin-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_nums(char **nums)
{
	int	i;

	i = 0;
	while ()
	{
		
	}
}

t_stack	*create_stack(char **nums)
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
		nums = ft_split(argv[1], " ");
	else
		nums = create_nums_str(argv);
	if (validate_nums(nums))
		create_stacks(nums);
	else
		return (0);
}
