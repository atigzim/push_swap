#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void max_sort_five(t_list **stack_a, t_list **stack_b)
{
	unsigned int i;
	//unsigned int j;
	
	i = ft_lstsize(*stack_a);
	//printf("j == %d",i);
	//i = get_range(j);
	//printf("i == %d",i);
	if(i == 2)
		tow(stack_a);
	if(i == 3)
		ft_three(stack_a,stack_b);
	if(i == 4 || i == 5)
		five(stack_a,stack_b);

}
int search_in_stack_a(t_list *stack_a, int *p, unsigned int range, unsigned int i)
{
	if(stack_a->content < p[i])
		return(0);
	while(i < range)
	{
		if(stack_a->content == p[i])
		{
			return(1);
		}
		i++;
	}
	return(2);
}
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void search_in_stack_b(t_list **stack_b)
{
	if((*stack_b)->next)
	{
		t_list *head;
		t_list *lst;

		lst = ft_lstlast(*stack_b);
		head = *stack_b;
		if (lst->content > head->content)
			rb(stack_b);
		else if (head->content < head->next->content)
			sb(stack_b);
	}

}



void posh_stack_a(t_list **stack_a, t_list **stack_b, int *p)
{
	unsigned int range;
	unsigned int size;
	unsigned int start;
	t_list *temp;

	size = ft_lstsize(*stack_a);
	range = get_range(size);
	start = 0;
	while(start < size)
	{
		temp = *stack_a;
		if(search_in_stack_a(temp,p,range,start) == 0)
			(pb(stack_a,stack_b), rb(stack_b));
		else if(search_in_stack_a(temp,p,range,start) == 1)
			(pb(stack_a,stack_b), search_in_stack_b(stack_b));
		else
		{
			ra(stack_a);
			continue ;
		}
		if(range < size)
			range++;
		start++;
	}
}
void ft_max(t_list *stack_a,t_list **node)
{
	t_list *temp;

	temp = stack_a->next;
	*node = stack_a;
	while (temp)
	{
		if((*node)->content < temp->content)
			*node = temp;
		temp = temp->next;
	}
}

int bigger_element(t_list *stack_b)
{
	int i;
	t_list *temp;
	t_list *head;

	i = 0;
	ft_max(stack_b,&temp);
	head = stack_b;
	while(head->content != temp->content)
	{
		i++;
		head = head->next;
	}
	return(i);
}
int bigger_small(t_list *stack_a)
{
	int i;
	t_list *temp;
	t_list *head;

	i = 0;
	ft_min(&stack_a,&temp);
	head = stack_a;
	while(head->content != temp->content)
	{
		i++;
		head = head->next;
	}
	return(i);
}

// void ra_rra(t_list **stack_a)
// {
// 	int size ;
// 	int i;
// 	t_list *node;
// 	i = bigger_small(stack_a);
// 	size = ft_lstsize(stack_a)/ 2;
// 	ft_min(stack_a,&node);
// 	if(i >= size)
// 		while((*stack_a)->content != node->content)
// 			rra(stack_a);
// 	else
// 		while((*stack_a)->content != node->content)
// 			ra(stack_a);
// }

void posh_stack_b(t_list **stack_a, t_list **stack_b)
{
	unsigned int i;
	unsigned int size;
	t_list *node;

	
	while(*stack_b)
	{
		i = bigger_element(*stack_b);
		size = ft_lstsize(*stack_b)/ 2;
		ft_max(*stack_b,&node);
		if(i >= size)
			while((*stack_b)->content != node->content)
				rrb(stack_b);
		else
			while((*stack_b)->content != node->content)
				rb(stack_b);
		pa(stack_a,stack_b);
	}
}

int main(int ac, char **av)
{
	if(ac > 1)
	{
		t_list *stack_a;
		t_list *stack_b;
		// t_list *head;
		int *p;

		stack_a = NULL;
		stack_b = NULL;
		p = parsing(&stack_a,av,ac);
		if(ft_lstsize(stack_a) <= 5)
			max_sort_five(&stack_a,&stack_b);
		else
		{
			posh_stack_a(&stack_a,&stack_b,p);
			posh_stack_b(&stack_a,&stack_b);
		}
		// head = stack_a;
		// while(head)
		// {
			
		// 	printf("(%d)->",head->content);
		// 	head = head->next;
		// }
		
	}
	else
		exit(1);
	
}