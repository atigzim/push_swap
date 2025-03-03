/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:34:04 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/01 10:50:06 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alpha(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isalpha(av[i]))
			error();
		i++;
	}
}

void	plus_and(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) && ((av[i + 1] == '-') || (av[i + 1] == '+')))
			error();
		if (((av[i] == '-') || (av[i] == '+')) && ((av[i + 1] == '-') || (av[i
					+ 1] == '+')))
			error();
		if (((av[i] == '-') || (av[i] == '+')) && !ft_isdigit(av[i + 1]))
			error();
		i++;
	}
}

void	repetition(t_list **stack)
{
	t_list	*tmp;
	t_list	*node;
	t_list	*next;

	tmp = *stack;
	node = tmp;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (node->content == next->content)
			{
				free_stack(stack);
				error();
			}
			next = next->next;
		}
		node = tmp->next;
		tmp = tmp->next;
	}
}

int	*bubble_sort(t_list **head)
{
	t_list	*tmp;
	int		*p;

	int(i), (j);
	i = ft_lstsize(*head);
	j = 0;
	tmp = *head;
	p = malloc(i * sizeof(int));
	if (!p)
	{
		free_stack(head);
		return (NULL);
	}
	while (i > j)
	{
		p[j] = tmp->content;
		j++;
		tmp = tmp->next;
	}
	loop_bubbel_sort(&p, j);
	return (p);
}

int	is_sort(t_list **stack_a)
{
	t_list	*head;
	t_list	*temp;

	head = *stack_a;
	temp = head->next;
	while (temp)
	{
		if (head->content > temp->content)
			return (1);
		temp = temp->next;
		head = head->next;
	}
	return (0);
}
