/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:58:12 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/26 18:58:16 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rev_rotate_stack(t_stack *s)
{
	t_node	*node;

	if (!s || s->size < 2)
		return (0);
	node = s->tail;
	s->tail->prev->next = NULL;
	s->tail = s->tail->prev;
	s->head->prev = node;
	node->next = s->head;
	node->prev = NULL;
	s->head = node;
	return (1);
}

void	op_rra(t_stack *a, t_config *cfg)
{
	if (rev_rotate_stack(a))
	{
		ft_putstr_fd("rra\n", 1);
		if (cfg)
		{
			cfg->ops.rra++;
			cfg->ops.total++;
		}
	}
}

void	op_rrb(t_stack *b, t_config *cfg)
{
	if (rev_rotate_stack(b))
	{
		ft_putstr_fd("rrb\n", 1);
		if (cfg)
		{
			cfg->ops.rrb++;
			cfg->ops.total++;
		}
	}
}

void	op_rrr(t_stack *a, t_stack *b, t_config *cfg)
{
	int	done_a;
	int	done_b;

	done_a = rev_rotate_stack(a);
	done_b = rev_rotate_stack(b);
	if (done_a || done_b)
	{
		ft_putstr_fd("rrr\n", 1);
		if (cfg)
		{
			cfg->ops.rrr++;
			cfg->ops.total++;
		}
	}
}
