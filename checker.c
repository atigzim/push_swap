/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:30 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/02 21:58:49 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parsinggg(t_list **stack_a, char **av, int ac)
{
	int	i;

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
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		t_list *stack_a;
		t_list *stack_b;
		char *get;
		int i;

		stack_a = NULL;
		stack_b = NULL;
		parsinggg(&stack_a, av, ac);
		get = get_next_line(1);
		while (get != NULL)
		{
			//printf("%s",get);
			if (ft_strcmp(get, "ra\n") == 0)
				ft_ra(&stack_a);
			else if (ft_strcmp(get, "rra\n") == 0)
				ft_rra(&stack_a);
			else if (ft_strcmp(get, "rb\n") == 0)
				ft_rb(&stack_a);
			else if (ft_strcmp(get, "sb\n") == 0)
				ft_sb(&stack_b);
			else if (ft_strcmp(get, "sa\n") == 0)
				ft_sa(&stack_a);
			else if (ft_strcmp(get, "pb\n") == 0)
				ft_pb(&stack_a, &stack_b);
			else if (ft_strcmp(get, "pa\n") == 0)
				ft_pa(&stack_a, &stack_b);
			else if (ft_strcmp(get, "rrb\n") == 0)
				ft_rrb(&stack_b);
			else
			{
				write(1, "KO\n", 3);
				if (stack_a)
					free_stack(&stack_a);
				if (stack_b)
					free_stack(&stack_b);
				free(get);
				exit(1);
			}
			free(get);
			get = get_next_line(1);
		}
		get_next_line(0);
		i = is_sort(&stack_a);
		if (i == 1)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		if (stack_a)
			free_stack(&stack_a);
		if (stack_b)
			free_stack(&stack_b);
	}
	else
		exit(1);
}