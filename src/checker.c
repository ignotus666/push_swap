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

static int	checker_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	**tokens;
	int		splited;

	splited = 0;
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (!tokens)
			return (0);
		splited = 1;
	}
	else
		tokens = &argv[1];
	if (!process_tokens(tokens, a))
	{
		if (splited)
			ft_free_split(tokens);
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (splited)
		ft_free_split(tokens);
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
			free_stack(a);
			free_stack(b);
			free(line);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
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
	if (!checker_args(argc, argv, &a, &b))
		return (1);
	if (checker_ops(&a, &b))
	{
		if (is_sorted(&a) && b.size == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
