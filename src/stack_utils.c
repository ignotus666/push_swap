/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 22:30:00 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/19 09:25:49 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_node	*create_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int	stack_append(t_stack *stack, int num)
{
	t_node	*node;

	node = create_node(num);
	if (!node)
		return (0);
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
	stack->size++;
	return (1);
}

int	has_duplicate(t_stack *stack, int num)
{
	t_node	*curr;

	if (!stack)
		return (0);
	curr = stack->head;
	while (curr)
	{
		if (curr->num == num)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	if (!stack)
		return ;
	curr = stack->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
