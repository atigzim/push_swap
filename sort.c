#include "push_swap.h"

int    get_range(int size)
{
    if (size <= 16)
        return (size / 2);
    else if (size <= 100)
        return (size / 5);
    else if (size <= 500)
        return (size / 12);
    else
        return (35);
}

void tow(t_list **stack_a)
{
	sa(stack_a);
}

void ft_min(t_list **stack_a, t_list *node)
{
	t_list *temp;

	temp = (*stack_a)->next;
	node = *stack_a;
	while (temp)
	{
		if(node->content > temp->content)
			node = temp;
		temp = temp->next;
	}
}
void	ft_three(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	t_list *temp1;
	t_list *temp2;
	
	temp = *stack_a;
	temp1 = temp->next;
	temp2 = temp1->next;
	if(temp->content > temp1->content && temp1->content > temp2->content)
	{
		rra(stack_a);
		pa(stack_a,stack_b);
		sa(stack_a);
		pb(stack_a,stack_b);
	}
	else if(temp->content > temp1->content && temp->content < temp2->content)
		sa(stack_a);
	else if(temp->content < temp1->content && temp->content > temp2->content)
		rra(stack_a);
	else if(temp->content < temp1->content && temp1->content > temp2->content)
	{
		pa(stack_a,stack_b);
		sa(stack_a);
		pb(stack_a,stack_b);
	}
	else if(temp->content > temp1->content && temp->content > temp2->content)
		ra(stack_a);
}

void	five(t_list **stack_a, t_list **stack_b)
{
	t_list *node;
	t_list *temp;
	t_list *head_b;
	int size;

	size = ft_lstsize(*stack_a);
	node = 0;
	while(size > 3)
	{
		temp = *stack_a;
		ft_min(stack_a,node);
		while(temp)
		{
			temp = *stack_a;
			if(node->content == temp->content)
			{
				pa(stack_a, stack_b);
				break ;
			}
			else
				ra(stack_a);
		}
		size--;
	}
	ft_three(stack_a,stack_b);
	head_b = *stack_b;
	while(head_b)
	{
		pb(stack_a,stack_b);
		head_b = *stack_b;
	}

}
