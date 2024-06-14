#include <stdio.h>
#include "list.h"

int ascending(int a, int b)
{
	return (a >= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list tmp;

    int i = 0;
    while ()
    if (cmp(lst->data, lst->next->data))
    {
        tmp->data = lst->data;
        lst->data = lst->next->data;
        lst->next->data = temp->data;
    }

}

int main(void)
{

}