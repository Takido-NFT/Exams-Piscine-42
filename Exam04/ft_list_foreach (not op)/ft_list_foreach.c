#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void    print_void(void *data)
{
    printf("Data = %s\n", (char *)data);
}

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        if (begin_list->data != NULL)
            f(begin_list->data);
        begin_list = begin_list->next;
    }
}

int main(void)
{
    t_list *begin_list;
    t_list *second;

    begin_list = malloc(sizeof(t_list));
    second = malloc(sizeof(t_list));
    if (!begin_list || !second)
        return 1;

    begin_list->data = "Hello World !";
    begin_list->next = second;

    second->data = "Second Sentence !";
    second->next = NULL;
    
    ft_list_foreach(begin_list, print_void);
    free(second);
    free(begin_list);
    return 0;
}