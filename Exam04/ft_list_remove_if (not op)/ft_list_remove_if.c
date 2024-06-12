#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

// Assume the previous definitions and implementations are available

int cmp(void *a, void *b) {
    return strcmp((char *)a, (char *)b);
}

void print_list(t_list *list) {
    while (list) {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		curr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(curr);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		curr = curr->next;
	}
}

int main() {
    t_list *list = malloc(sizeof(t_list));
    t_list *second = malloc(sizeof(t_list));
    t_list *third = malloc(sizeof(t_list));
    t_list *fourth = malloc(sizeof(t_list));

    list->data = "Hello";
    list->next = second;
    second->data = "World";
    second->next = third;
    third->data = "Hello";
    third->next = fourth;
    fourth->data = "42";
    fourth->next = NULL;

    printf("Original list:\n");
    print_list(list);

    ft_list_remove_if(&list, "Hello", cmp);

    printf("Modified list:\n");
    print_list(list);

    // Free remaining nodes
    free(second);
    free(fourth);

    return 0;
}
