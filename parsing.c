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

int	chick(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (i == ' ')
		{
			i = 1;
			return (i);
		}
		i++;
	}
	return (0);
}

t_list	*one_arg(char *av)
{
	t_list	*new_node;
	int		j;

	j = ft_atoi(av);
	
	new_node = ft_lstnew(j);
	return (new_node);
}
t_list	*tow_arg(char *av)
{
	char	**arg;
	int		i;
	int		j;
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
		new_node = ft_lstnew(j);
		if (!head)
			head = new_node;
		else
			ft_lstadd_back(&head, new_node);
		i++;
	}
	return (head);
}

void	new_stack(char **av, t_list **head)
{
	t_list	*new_node;
	int		i;

	i = 1;
	
	while (av[i])
	{
		if (chick(av[i]) == 0)
			new_node = tow_arg(av[i]);
		else
			new_node = one_arg(av[i]);
		if (!head)
			*head = new_node;
		else
			ft_lstadd_back(head, new_node);
		i++;
	}
	// printf("%d",(*head)->content);
}

int	*parsing(t_list **stack_a, char **av, int ac)
{
	int	i;
	int *p;

	i = 1;
	//p = 0;
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
	// printf("%d",(*stack_a)->content);
	repetition(stack_a);
	i = is_sort(stack_a);
   	p = bubble_sort(stack_a);
	// printf("%d",p[0]);
	return p;
}
