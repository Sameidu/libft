#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *current; // Se obtiene el puntero al primer nodo de la lista
	t_list *next;

    current = *lst;
	while (current != NULL) // Se recorre la lista hasta llegar al final
	{
		next = current->next; // Se guarda el puntero al siguiente nodo
		if (del != NULL) // Se verifica si se ha proporcionado una función para eliminar el contenido del nodo
			del(current->content); // Se llama a la función para eliminar el contenido del nodo
		free(current); // Se libera la memoria ocupada por el nodo
		current = next; // Se avanza al siguiente nodo
	}
	*lst = NULL; // Se establece el puntero a la lista como nulo
}