#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  temp;

    temp = *lst;
    if (*lst)
    {
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
    else
        *lst = new;
}