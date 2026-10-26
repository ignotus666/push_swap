/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:46:26 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/22 14:39:36 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!s || s->size < 2)
		return (0);
	first = s->head;
	second = first->next;
	third = second->next;
	s->head = second;
	s->head->prev = NULL;
	s->head->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	else
		s->tail = first;
	return (1);
}

void	op_sa(t_stack *a, t_config *cfg)
{
	if (swap_stack(a))
	{
		ft_putstr_fd("sa\n", 1);
		if (cfg)
		{
			cfg->ops.sa++;
			cfg->ops.total++;
		}
	}
}

void	op_sb(t_stack *b, t_config *cfg)
{
	if (swap_stack(b))
	{
		ft_putstr_fd("sb\n", 1);
		if (cfg)
		{
			cfg->ops.sb++;
			cfg->ops.total++;
		}
	}
}

void	op_ss(t_stack *a, t_stack *b, t_config *cfg)
{
	int	done_a;
	int	done_b;

	done_a = swap_stack(a);
	done_b = swap_stack(b);
	if (done_a || done_b)
	{
		ft_putstr_fd("ss\n", 1);
		if (cfg)
		{
			cfg->ops.ss++;
			cfg->ops.total++;
		}
	}
}
