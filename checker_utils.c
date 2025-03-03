/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:24 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/01 18:02:25 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	search_in_stack_a(t_list *stack_a, int *p, unsigned int range,
		unsigned int i)
{
	if (stack_a->content < p[i])
		return (0);
	while (i < range)
	{
		if (stack_a->content == p[i])
		{
			return (1);
		}
		i++;
	}
	return (2);
}

void	loop_bubbel_sort(int **pr, int j)
{
	int	i;
	int	c;
	int	*p;

	i = 0;
	p = *pr;
	while (i < j - 1)
	{
		if (p[i] > p[i + 1])
		{
			c = p[i];
			p[i] = p[i + 1];
			p[i + 1] = c;
			i = 0;
		}
		else
			i++;
	}
}
