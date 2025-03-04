/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:30 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/04 01:41:18 by atigzim          ###   ########.fr       */
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

int	mov(t_list **stack_a, t_list **stack_b, char *get)
{
	if (ft_strcmp(get, "ra\n") == 0)
		return (ft_ra(stack_a), 1);
	else if (ft_strcmp(get, "rra\n") == 0)
		return (ft_rra(stack_a), 1);
	else if (ft_strcmp(get, "rb\n") == 0)
		return (ft_rb(stack_a), 1);
	else if (ft_strcmp(get, "sb\n") == 0)
		return (ft_sb(stack_b), 1);
	else if (ft_strcmp(get, "sa\n") == 0)
		return (ft_sa(stack_a), 1);
	else if (ft_strcmp(get, "ss\n") == 0)
		return (ft_ss(stack_a, stack_b), 1);
	else if (ft_strcmp(get, "pb\n") == 0)
		return (ft_pb(stack_a, stack_b), 1);
	else if (ft_strcmp(get, "pa\n") == 0)
		return (ft_pa(stack_a, stack_b), 1);
	else if (ft_strcmp(get, "rrb\n") == 0)
		return (ft_rrb(stack_b), 1);
	else if (ft_strcmp(get, "rr\n") == 0)
		return (ft_rr(stack_a, stack_b), 1);
	else if (ft_strcmp(get, "rrr\n") == 0)
		return (ft_rrr(stack_a, stack_b), 1);
	return (0);
}

void	loop_get(char *get, t_list **stack_a, t_list **stack_b)
{
	int	i;

	while (get)
	{
		i = mov(stack_a, stack_b, get);
		if (i == 0)
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			free_stack(stack_b);
			if (get)
				free(get);
			exit(1);
		}
		if (get)
			free(get);
		get = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*get;
	int		i;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		parsinggg(&stack_a, av, ac);
		get = get_next_line(0);
		loop_get(get, &stack_a, &stack_b);
		i = is_sort(&stack_a);
		if (i == 1 || stack_b)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	else
		exit(0);
}
