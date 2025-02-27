/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:33:56 by atigzim           #+#    #+#             */
/*   Updated: 2025/02/27 14:47:15 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		rrb(stack_b);
	else if (!stack_b)
		rra(stack_a);
	else
	{
		rrb(stack_b);
		rra(stack_a);
	}
	write(1, "rrr\n", 4);
}

int	chick(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	bigger_element(t_list *stack_b)
{
	int		i;
	t_list	*temp;
	t_list	*head;

	i = 0;
	ft_max(stack_b, &temp);
	head = stack_b;
	while (head->content != temp->content)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	bigger_small(t_list *stack_a)
{
	int		i;
	t_list	*temp;
	t_list	*head;

	i = 0;
	ft_min(&stack_a, &temp);
	head = stack_a;
	while (head->content != temp->content)
	{
		i++;
		head = head->next;
	}
	return (i);
}
