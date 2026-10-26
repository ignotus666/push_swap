/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-l <jmarin-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:43:01 by jmarin-l          #+#    #+#             */
/*   Updated: 2026/10/26 13:43:17 by jmarin-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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