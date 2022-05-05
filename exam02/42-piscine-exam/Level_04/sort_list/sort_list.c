#include <stdio.h>
#include <stdlib.h>

typedef struct lst
{
	int data;
	struct lst *next;
}t_list;
int ascending(int a, int b)
{
	return (a <= b);
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap;
	t_list *tmp;

	tmp = lst;
	while (lst->next != 0)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
int main ()
{
	t_list *new;
	t_list *new1;
	t_list *new2;

	int a = 5;
	int b = 6;
	int c = 2;

	new = (t_list *)malloc(sizeof(t_list));
	new1 = (t_list *)malloc(sizeof(t_list));
	new2 = (t_list *)malloc(sizeof(t_list));
	
	new->data = 5;
	new->next = new1;
	new1->data = 6;
	new1->next = new2;
	new2->data = 2;
	new2->next = NULL;

	sort_list (new, ascending);
	printf("%d\n", new->data);
}