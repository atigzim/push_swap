
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				error(void);
int					ft_isdigit(int c);
void				free_stack(t_list **stack);
int					ft_isalpha(int c);
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
long				ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
unsigned int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void				five(t_list **stack_a, t_list **stack_b);
void				ft_three(t_list **stack_a, t_list **stack_b);
int		*parsing(t_list **stack_a, char **av, int ac);
void	new_stack(char **av, t_list **head);
void	space(char *av);
int		chick(char *av);
int		is_sort(t_list **stack_a);
int 	*bubble_sort(t_list **head);
void	repetition(t_list **stack);
void	plus_and(char *av);
void	alpha(char *av);
void ft_min(t_list **stack_a,t_list **node);
void ft_max(t_list *stack_a,t_list **node);
unsigned int   get_range(unsigned int size);
void tow(t_list **stack_a);
void search_in_stack_b(t_list **stack_b);
int search_in_stack_a(t_list *stack_a, int *p, unsigned int range, unsigned int i);
void posh_stack_a(t_list **stack_a, t_list **stack_b, int *p);
int bigger_element(t_list *stack_b);
// void ra_rra(t_list *stack_a);

#endif