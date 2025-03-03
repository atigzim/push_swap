/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_checker_tow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:46 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/02 21:58:33 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;

	if ((*stack_a)->next)
	{
		head = *stack_a;
		tmp = head->next;
		head->next = NULL;
		*stack_a = tmp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = head;
	}
}

void	ft_rb(t_list **stack_b)
{
	
	t_list	*tmp;
	t_list	*head;

	if ((*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		head = *stack_b;
		*stack_b = tmp;
		head->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = head;
		//write(1,"hhh\n",4);
	}
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		rb(stack_b);
	else if (!stack_b)
		ra(stack_a);
	else
	{
		rb(stack_b);
		ra(stack_a);
	}
}

void	ft_rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*lst;

	if ((*stack_a)->next)
	{
		head = *stack_a;
		tmp = head;
		lst = head;
		while (tmp->next)
			tmp = tmp->next;
		while (lst->next->next)
			lst = lst->next;
		lst->next = NULL;
		tmp->next = head;
		*stack_a = tmp;
	}
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*lst;

	if ((*stack_b)->next)
	{
		head = *stack_b;
		tmp = head;
		lst = head;
		while (tmp->next)
			tmp = tmp->next;
		while (lst->next->next)
			lst = lst->next;
		lst->next = NULL;
		tmp->next = head;
		*stack_b = tmp;
	}
}
