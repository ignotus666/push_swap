/* 42 Header */

#include "push_swap.h"

static int	push_stack(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src || src->size == 0)
		return (0);
	node = src->head;
	src->head = node->next;
	if (src->head)
		src->head->prev = NULL;
	else	
		src->tail = NULL;
	src->size--;
	node->next = dst->head;
	node->prev = NULL;
	if (dst->head)
		dst->head->prev = node;
	else
		dst->tail = node;
	dst->head = node;
	dst->size++;
	return (1);
}

void	op_pa(t_stack *a, t_stack *b, t_config *cfg)
{
	if (push_stack(a, b))
	{
		ft_putstr_fd("pa\n", 1);
		if (cfg)
		{
			cfg->ops.pa++;
			cfg->ops.total++;
		}
	}
}

void	op_pb(t_stack *a, t_stack *b, t_config *cfg)
{
	if (push_stack(b, a))
	{
		ft_putstr_fd("pb\n", 1);
		if (cfg)
		{
			cfg->ops.pb++;
			cfg->ops.total++;
		}
	}
}