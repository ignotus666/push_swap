/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-l <jmarin-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:29:48 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/19 15:15:33 by jmarin-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *a)
{
	t_node	*node;
	size_t	size;

	if (!a->head)
		return (0);
	node = a->head;
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

int	node_num(t_stack *a, int index)
{
	t_node	*node;

	node = a->head;
	while (index != 0)
	{
		node = node->next;
		index--;
	}
	return (node->num);
}

float	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_size(a))
	{
		j = i + 1;
		while (j < stack_size(a))
		{
			total_pairs++;
			if (node_num(a, i) > node_num(a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
