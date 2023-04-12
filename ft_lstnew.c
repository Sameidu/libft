#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list  *list;

    list = malloc(sizeof(t_list));
    if (!list)
        return (NULL);
    list->content = content;
    list->next = NULL;
    return (list);
}
/*
int main(void)
{
    t_list *paco;
    int i = 1;

    paco = ft_lstnew(&i);
    printf("%i", *(int *)paco->content);
    return(0);
}*/