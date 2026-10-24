/* 42 Header */

#include "push_swap.h"

static int	get_min(t_stack *s, int *index)
{
	t_node	*node;
	int	min;
	int	i;

	node = s->head;
	min = node->num;
	i = 1;
	*index = 1;
	while (node)
	{
		if (node->num < min)
		{
			min = node->num;
			*index = i;
		}
		node = node->next;
		i++;
	}
	return (min);
}

void	alg_simple(t_stack *a, t_stack *b, t_config *cfg)
{
	int	min;
	int	index;

	if (!a || !cfg || a->size < 2)
		return ;
	while (a->size != 0)
	{
		min = get_min(a, &index);
		if (index < (a->size / 2))
		{
			while (a->head->num != min)
				op_ra(a, cfg);
		}	
		else
		{
			while (a->head->num != min)
				op_rra(a, cfg);
		}
		op_pb(a, b, cfg);
	}
	while (b->size != 0)
		op_pa(a, b, cfg);
}
