/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:34:11 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/03 22:04:44 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
