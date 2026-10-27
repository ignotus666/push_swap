/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_adaptive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:46:16 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/27 16:09:25 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	extract_unordered_to_b(t_stack *a, t_stack *b, t_config *cfg)
{
	int	init_size;
	int	prev_idx;
	int	i;

	init_size = a->size;
	prev_idx = -1;
	i = 0;
	while (i < init_size)
	{
		if (a->head->index > prev_idx)
		{
			prev_idx = a->head->index;
			op_ra(a, cfg);
		}
		else
			op_pb(a, b, cfg);
		i++;
	}
}

static void	reinsert_in_a(t_stack *a, t_stack *b, t_config *cfg)
{
	int	to_move;

	while (b->size > 0)
	{
		to_move = b->head->index;
		if (a->size < 2)
			op_pa(a, b, cfg);
		else if (a->tail->index > a->head->index
			&& (to_move < a->head->index || to_move > a->tail->index))
			op_pa(a, b, cfg);
		else if (a->tail->index < to_move && a->head->index > to_move)
			op_pa(a, b, cfg);
		else
			op_ra(a, cfg);
	}
}

static void	alg_low_disorder(t_stack *a, t_stack *b, t_config *cfg)
{
	index_nodes(a);
	extract_unordered_to_b(a, b, cfg);
	reinsert_in_a(a, b, cfg);
	while (a->head->index != 0)
		op_ra(a, cfg);
}

void	alg_adaptive(t_stack *a, t_stack *b, t_config *cfg)
{
	if (cfg->disorder < 0.2f)
		alg_low_disorder(a, b, cfg);
	else if (cfg->disorder < 0.5f)
		alg_medium(a, b, cfg);
	else
		alg_complex(a, b, cfg);
}
