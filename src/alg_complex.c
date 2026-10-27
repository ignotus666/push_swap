/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:10:25 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/27 12:35:36 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	max_num;
	int	max_bits;

	max_num = a->size - 1;
	max_bits = 0;
	while (max_num > 0)
	{
		max_num = max_num / 2;
		max_bits++;
	}
	return (max_bits);
}

void	alg_complex(t_stack *a, t_stack *b, t_config *cfg)
{
	int	max_bits;
	int	curr_bit;
	int	j;

	index_nodes(a);
	max_bits = get_max_bits(a);
	curr_bit = 0;
	while (curr_bit < max_bits)
	{
		j = a->size;
		while (j > 0)
		{
			if ((a->head->index >> curr_bit) & 1)
				op_ra(a, cfg);
			else
				op_pb(a, b, cfg);
			j--;
		}
		while (b->size > 0)
			op_pa(a, b, cfg);
		curr_bit++;
	}
}
