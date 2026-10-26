/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:59:10 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/26 18:59:13 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack *s)
{
	t_node	*node;

	if (!s || s->size < 2)
		return (0);
	node = s->head;
	s->head = node->next;
	s->head->prev = NULL;
	s->tail->next = node;
	node->next = NULL;
	node->prev = s->tail;
	s->tail = node;
	return (1);
}

void	op_ra(t_stack *a, t_config *cfg)
{
	if (rotate_stack(a))
	{
		ft_putstr_fd("ra\n", 1);
		if (cfg)
		{
			cfg->ops.ra++;
			cfg->ops.total++;
		}
	}
}

void	op_rb(t_stack *b, t_config *cfg)
{
	if (rotate_stack(b))
	{
		ft_putstr_fd("rb\n", 1);
		if (cfg)
		{
			cfg->ops.rb++;
			cfg->ops.total++;
		}
	}
}

void	op_rr(t_stack *a, t_stack *b, t_config *cfg)
{
	int	done_a;
	int	done_b;

	done_a = rotate_stack(a);
	done_b = rotate_stack(b);
	if (done_a || done_b)
	{
		ft_putstr_fd("rr\n", 1);
		if (cfg)
		{
			cfg->ops.rr++;
			cfg->ops.total++;
		}
	}
}
