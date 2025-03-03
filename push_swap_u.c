/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:34:09 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/01 15:29:41 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rra(t_list **stack_a, int size)
{
	int	i;

	i = bigger_small(*stack_a);
	if (i <= size / 2)
		ra(stack_a);
	else
		rra(stack_a);
}

void	ft_max(t_list *stack_a, t_list **node)
{
	t_list	*temp;

	temp = stack_a->next;
	*node = stack_a;
	while (temp)
	{
		if ((*node)->content < temp->content)
			*node = temp;
		temp = temp->next;
	}
}
void	posh_stack_b(t_list **stack_a, t_list **stack_b)
{
	unsigned int	i;
	unsigned int	size;
	t_list			*node;

	while (*stack_b)
	{
		i = bigger_element(*stack_b);
		size = ft_lstsize(*stack_b) / 2;
		ft_max(*stack_b, &node);
		if (i >= size)
			while ((*stack_b)->content != node->content)
				rrb(stack_b);
		else
			while ((*stack_b)->content != node->content)
				rb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	search_in_stack_b(t_list **stack_b)
{
	t_list	*head;
	t_list	*lst;

	if ((*stack_b)->next)
	{
		lst = ft_lstlast(*stack_b);
		head = *stack_b;
		if (lst->content > head->content)
			rb(stack_b);
		else if (head->content < head->next->content)
			sb(stack_b);
	}
}

void	max_sort_five(t_list **stack_a, t_list **stack_b)
{
	unsigned int	i;

	i = ft_lstsize(*stack_a);
	if (i == 2)
		tow(stack_a);
	if (i == 3)
		ft_three(stack_a);
	if (i == 4 || i == 5)
		five(stack_a, stack_b);
}

void	posh_stack_a(t_list **stack_a, t_list **stack_b, int *p)
{
	unsigned int	range;
	unsigned int	size;
	unsigned int	start;
	t_list			*temp;

	size = ft_lstsize(*stack_a);
	range = get_range(size);
	start = 0;
	while (start < size)
	{
		temp = *stack_a;
		if (search_in_stack_a(temp, p, range, start) == 0)
			(pb(stack_a, stack_b), rb(stack_b));
		else if (search_in_stack_a(temp, p, range, start) == 1)
			(pb(stack_a, stack_b), search_in_stack_b(stack_b));
		else
		{
			ra(stack_a);
			continue ;
		}
		if (range < size)
			range++;
		start++;
	}
}
