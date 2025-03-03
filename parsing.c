/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:33:59 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/03 00:14:09 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	space(char *av)
{
	int	i;

	i = 0;
	while (av[i] == 32)
		i++;
	if (av[i] == '\0')
		error();
}

t_list	*one_arg(char *av, t_list **stack_a)
{
	t_list	*new_node;
	long	j;

	j = ft_atoi(av);
	if (j == 21474836418)
	{
		free_stack(stack_a);
		error();
	}
	new_node = ft_lstnew(j);
	return (new_node);
}

t_list	*tow_arg(char *av, t_list **stack_a)
{
	char	**arg;
	int		i;
	long	j;
	t_list	*head;
	t_list	*new_node;

	head = NULL;
	i = 0;
	if (!av[i])
		error();
	arg = ft_split(av, ' ');
	while (arg[i])
	{
		j = ft_atoi(arg[i]);
		if (j == 21474836418)
			(free_stack(stack_a), error());
		new_node = ft_lstnew(j);
		if (!head)
			head = new_node;
		else
			ft_lstadd_back(&head, new_node);
		i++;
	}
	free_chars(arg);
	return (head);
}

void	new_stack(char **av, t_list **head)
{
	t_list	*new_node;
	int		i;

	i = 1;
	while (av[i])
	{
		if (chick(av[i]) != 0)
			new_node = tow_arg(av[i], head);
		else
			new_node = one_arg(av[i], head);
		if (!head)
			*head = new_node;
		else
			ft_lstadd_back(head, new_node);
		i++;
	}
}

int	*parsing(t_list **stack_a, char **av, int ac)
{
	int	i;
	int	*p;

	i = 1;
	while (ac > i)
	{
		if (!av[i][0])
			error();
		space(av[i]);
		alpha(av[i]);
		plus_and(av[i]);
		i++;
	}
	new_stack(av, stack_a);
	repetition(stack_a);
	p = bubble_sort(stack_a);
	i = is_sort(stack_a);
	if (i == 0)
	{
		free(p);
		free_stack(stack_a);
		exit(0);
	}
	return (p);
}
