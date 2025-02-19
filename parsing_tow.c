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
	t_list(*tmp), (*node), (*next);
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

int *bubble_sort(t_list **head)
{
    t_list *tmp;
    int i;
    int j;
    int c;
	int *p;
    i = ft_lstsize(*head);
    j = 0;
    tmp = *head;
    p = malloc(i * sizeof(int));
    if(!p)
    {
        free_stack(head);
    }
    while(i > j)
    {
        p[j] = tmp->content;
        j++;
        tmp = tmp->next;
    }
    i = 0;
    while(i < j - 1)
    {
        if(p[i] > p[i + 1])
        {
            c = p[i];
            p[i] = p[i + 1];
            p[i + 1] = c;
            i = 0;
        }
        else
            i++;
    }
	return (p);
    
}

int	is_sort(t_list **stack_a)
{
	t_list *head;
	t_list *temp;

	head = *stack_a;
	temp = head->next;
	while (temp)
	{
		if(head->content > temp->content)
			return (1);
		temp = temp->next;
		head = head->next;
	}
	free_stack(stack_a);
	exit(0);
}