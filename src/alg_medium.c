

#include "push_swap.h"

static t_node	*get_first_unindexed(t_stack *a)
{
	t_node	*node;

	if (!a)
		return (NULL);
	node = a->head;
	while (node && node->index != -1)
		node = node->next;
	return (node);
}

static void	index_nodes(t_stack *a)
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

static int	ft_sqrt(int n)
{
	int	i;
	if (n < 4)
		return (1);
	i = 2;
	while (i < n)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (0);
}

static void	build_a(t_stack *a, t_stack *b, t_config *cfg)
{
	int	max;
	int	index;

	if (!b || !cfg || b->size < 2)
		return ;
	while (b->size != 0)
	{
		max = get_max(b, &index);
		if (index < (b->size / 2))
		{
			while (b->head->num != max)
				op_rb(b, cfg);
		}
		else
		{
			while (b->head->num != max)
				op_rrb(b, cfg);
		}
		op_pa(a, b, cfg);
	}
}

void	alg_medium(t_stack *a, t_stack *b, t_config *cfg)
{
	int		chunk_size;
	int		min_idx;
	int		max_idx;
	int		i;
	t_node	*node;

	if (!a || !cfg || a->size < 2)
		return ;
	index_nodes(a);
	chunk_size = ft_sqrt(a->size);
	i = 0;
	while (a->size != 0)
	{
		node = a->head;
		min_idx = i * chunk_size;
		max_idx = min_idx + chunk_size - 1;
		while (node)
		{
			if (node->index > max_idx)
				op_ra(a, cfg);
			else
				op_pb(a, b, cfg);
			node = node->next;
		}
		i++;
	}
	build_a(a, b, cfg);
}