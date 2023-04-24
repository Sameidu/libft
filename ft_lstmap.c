#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *list = NULL; // Se crea una nueva lista enlazada vacía
	t_list *node; // Puntero al nuevo nodo creado

	while (lst != NULL) // Se recorre la lista original hasta llegar al final
	{
		node = ft_lstnew(f(lst->content)); // Se crea un nuevo nodo con el resultado de aplicar la función f al contenido del nodo actual
		if (node == NULL) // Se verifica si se pudo asignar memoria para el nuevo nodo
		{
			ft_lstclear(&list, del); // Se llama a ft_lstclear para eliminar los nodos creados hasta ahora y liberar la memoria
			return (NULL); // Se retorna nulo indicando que no se pudo crear la nueva lista
		}
		ft_lstadd_back(&list, node); // Se agrega el nuevo nodo a la nueva lista enlazada
		lst = lst->next; // Se avanza al siguiente nodo de la lista original
	}
	return (list); // Se retorna la nueva lista enlazada creada
}