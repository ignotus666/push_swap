/* 42 Header */

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

void	alg_medium(t_stack *a, t_stack *b, t_config *cfg)
{
	int	chunk_size;

	if (!a || !cfg || a->size < 2)
		return ;
	index_nodes(a);
	chunk_size = ft_sqrt(a->size);
}