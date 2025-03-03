/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_checker_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:02:43 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/01 18:02:44 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		rrb(stack_b);
	else if (!stack_b)
		rra(stack_a);
	else if (stack_a && stack_b)
	{
		rrb(stack_b);
		rra(stack_a);
	}
}
