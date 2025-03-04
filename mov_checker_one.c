/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_checker_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:01:38 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/04 00:54:41 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;
	int		i;

	i = ft_lstsize(*stack_a);
	if (i < 2)
		return ;
	if (*stack_a)
	{
		head = *stack_a;
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = head;
		*stack_a = tmp;
	}
}

void	ft_sb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head;
	int		i;

	i = ft_lstsize(*stack_b);
	if (i < 2)
		return ;
	if (*stack_b)
	{
		head = *stack_b;
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = head;
		*stack_b = tmp;
	}
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		ft_sb(stack_b);
	else if (!stack_b)
		ft_sa(stack_a);
	else if (stack_a && stack_b)
	{
		ft_sb(stack_b);
		ft_sa(stack_a);
	}
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tmp_a;

	if (*stack_a)
	{
		head_a = *stack_a;
		head_b = *stack_b;
		tmp_a = head_a->next;
		head_a->next = head_b;
		*stack_a = tmp_a;
		*stack_b = head_a;
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tmp_b;

	if (!(*stack_b))
		return ;
	head_a = *stack_a;
	head_b = *stack_b;
	tmp_b = head_b->next;
	head_b->next = head_a;
	*stack_b = tmp_b;
	*stack_a = head_b;
}
