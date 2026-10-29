/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:59:32 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/29 16:23:10 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	checker_args(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_number_arg(argv[i], a))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(a);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	checker_ops(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!run_op(line, a, b))
		{
			free(line);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	if (!checker_args(argc, argv, &a))
		return (1);
	if (!checker_ops(&a, &b))
	{
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	if (is_sorted(&a) && b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
