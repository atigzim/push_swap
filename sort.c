/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:34:29 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/01 10:45:54 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_range(unsigned int size)
{
	if (size <= 16)
		return (size / 2);
	else if (size <= 100)
		return (16);
	else
		return (38);
}

void	tow(t_list **stack_a)
{
	sa(stack_a);
}

void	ft_min(t_list **stack_a, t_list **node)
{
	t_list	*temp;

	temp = (*stack_a)->next;
	*node = *stack_a;
	while (temp)
	{
		if ((*node)->content > temp->content)
			*node = temp;
		temp = temp->next;
	}
}

void	ft_three(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp1;
	t_list	*temp2;

	while (is_sort(stack_a) == 1)
	{
		temp = *stack_a;
		temp1 = temp->next;
		temp2 = temp1->next;
		if ((temp->content > temp1->content && temp1->content > temp2->content))
			ra(stack_a);
		else if (temp->content > temp1->content)
			sa(stack_a);
		else if (temp->content < temp1->content
			&& temp1->content > temp2->content)
			rra(stack_a);
	}
}

void	five(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*temp;
	int		size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		ft_min(stack_a, &node);
		temp = *stack_a;
		while (temp)
		{
			temp = *stack_a;
			if (node->content == temp->content)
			{
				pb(stack_a, stack_b);
				break ;
			}
			else
				ra_rra(stack_a, size);
		}
		size--;
	}
	ft_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
