/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:43:01 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/27 10:19:55 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_first_unindexed(t_stack *a)
{
	t_node	*node;

	if (!a)
		return (NULL);
	node = a->head;
	while (node && node->index != -1)
		node = node->next;
	return (node);
}

void	index_nodes(t_stack *a)
{
	t_node	*node;
	t_node	*min;
	int		i;

	if (!a)
		return ;
	i = 0;
	while (i < a->size)
	{
		node = a->head;
		min = get_first_unindexed(a);
		while (node)
		{
			if (node->num < min->num && node->index == -1)
				min = node;
			node = node->next;
		}
		min->index = i;
		i++;
	}
}

int	get_max(t_stack *s, int *index)
{
	t_node	*node;
	int		max;
	int		i;

	node = s->head;
	max = node->num;
	i = 0;
	*index = 0;
	while (node)
	{
		if (node->num > max)
		{
			max = node->num;
			*index = i;
		}
		node = node->next;
		i++;
	}
	return (max);
}
