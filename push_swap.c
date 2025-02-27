/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:34:11 by atigzim           #+#    #+#             */
/*   Updated: 2025/02/27 15:00:48 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*p;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		p = parsing(&stack_a, av, ac);
		if (ft_lstsize(stack_a) <= 5)
			max_sort_five(&stack_a, &stack_b);
		else
		{
			posh_stack_a(&stack_a, &stack_b, p);
			posh_stack_b(&stack_a, &stack_b);
		}
		free(p);
		free_stack(&stack_a);
	}
	else
		exit(1);
}
