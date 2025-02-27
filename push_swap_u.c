/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:34:09 by atigzim           #+#    #+#             */
/*   Updated: 2025/02/27 15:37:49 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_bubbel_sort(int **pr, int j)
{
	int	i;
	int	c;
	int	*p;

	i = 0;
	p = *pr;
	while (i < j - 1)
	{
		if (p[i] > p[i + 1])
		{
			c = p[i];
			p[i] = p[i + 1];
			p[i + 1] = c;
			i = 0;
		}
		else
			i++;
	}
}

int	search_in_stack_a(t_list *stack_a, int *p, unsigned int range,
		unsigned int i)
{
	if (stack_a->content < p[i])
		return (0);
	while (i < range)
	{
		if (stack_a->content == p[i])
		{
			return (1);
		}
		i++;
	}
	return (2);
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
