#include "list.h"
#include <stdio.h>/////////////////
#include <stdlib.h>
int cmp(int a, int b)
{
	return (a <= b);
}

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *begin;
	t_list *tmp;

	begin = lst;
	tmp = lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			tmp = lst;
			lst = lst->next;
			lst->next = tmp;
			lst = begin; //return to start after this
		}
		else
			lst = lst->next;
	}
	return (begin);
}

// void list(t_list **begin)
// {
	
// 	t_list *list;
// 	int i = 5;
// 	//begin = list;
// 	list = *begin;
// 	while (i > 0)
// 	{
// 		list = (t_list*)malloc(sizeof(t_list));
// 		list->data = i;
// 		list = list->next;
// 		i--;
// 	}
// 	list = NULL;
// }

// int main()
// {
// 	int i = 0;
// 	t_list *list = NULL;
// 	list(&list);
// 	while (i < 4)
// 	{
// 		printf("%d\n", list->data);
// 		list = list->next;
// 		i++;
// 	}
// 	return 0;
// }


int main()
{
	t_list *list = NULL;
	t_list *begin = NULL;
	t_list *newlist;
	int i = 5;
	//begin = list;
	list = 0;
	begin = list;
	/*while (i > 0)
	{
		list->data = i;
		list->next = (t_list*)malloc(sizeof(t_list));
		list = list->next;
		i--;
	}*/
	while (i > 0)
	{
		newlist = (t_list*)malloc(sizeof(t_list));
		newlist->data = i;
		newlist->next = 0;
		if (!begin)
			begin = newlist;
		if (!list)
			list = newlist;
		else
		{
			list->next = newlist;
			list = newlist;
		}
		i--;
	}
	while (begin != 0)
	{
		printf("%d\n", begin->data);
		begin = begin->next;
		i++;
	}
	return 0;
}


// int main()
// {
// 	t_list *list = NULL;
// 	t_list *begin = NULL;
// 	int i = 5;
// 	//begin = list;

// 	while (i > 0)
// 	{
// 		list = (t_list*)malloc(sizeof(t_list));
// 		if (begin != NULL)
// 		{
// 			list->data = i;
// 			list = list->next;
// 		}
// 		else
// 			begin = list;
// 		i--;
// 	}
// 	//free(list);
// 	list = NULL;
// 	list = begin;
// 	while (i < 6)
// 	{
// 		printf("%d\n", list->data);
// 		list = list->next;
// 		i++;
// 	}
// 	return 0;
// }
