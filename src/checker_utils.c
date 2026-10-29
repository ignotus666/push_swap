/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:50:29 by marvin            #+#    #+#             */
/*   Updated: 2026/10/29 12:50:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_rotates(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		rotate_stack(a);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rotate_stack(b);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rev_rotate_stack(a);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rev_rotate_stack(b);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
	{
		rev_rotate_stack(a);
		rev_rotate_stack(b);
	}
	else
		return (0);
	return (1);
}

int	run_op(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		swap_stack(a);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		swap_stack(b);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		push_stack(a, b);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		push_stack(b, a);
	else
		return (run_rotates(line, a, b));
	return (1);
}