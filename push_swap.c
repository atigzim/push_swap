#include "push_swap.h"
 #include <stdio.h>

int main(int ac, char **av)
{
	if(ac > 1)
	{
		t_list *stack_a;
		t_list *head;

		stack_a = NULL;
		parsing(&stack_a,av,ac);
		head = stack_a;
	}
	else
		error();
	
}