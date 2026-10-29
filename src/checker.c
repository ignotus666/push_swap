/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-l <jmarin-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:59:32 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/28 16:14:04 by jmarin-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	is_sorted(t_stack *a)
{
	t_node	*curr;

	if (!a || !a->head)
		return (1);
	curr = a->head;
	while (curr->next != NULL)
	{
		if (curr->num > curr->next->num)
			return (0);
		curr = curr->next;
	}
	return (1);
}

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

static int	run_op(char *line, t_stack *a, t_stack *b)
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

int	main(int argc, char **argv)
{
	char	**tokens;

	if (argc < 2)
		return (0);
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else
		tokens = argv;
	if (!checker_parse(tokens))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	
}