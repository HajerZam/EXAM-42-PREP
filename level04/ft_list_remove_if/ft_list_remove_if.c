/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:59:07 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/10 14:43:32 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *prev;

	current = *begin_list;
	prev = NULL;
	while (*begin_list)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (previous)
			{
				prev->next = current->next;
			}
			else
			{
				*begin_list = current;
			}
			free(current);
			current = prev ? prev->next : *begin_list;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

// Explanation:
// t_list *current: Points to the current node in the list.
// t_list *previous: Tracks the previous node to correctly update the list when we remove a node.

// Traversal: The list is traversed using a while (current) loop.

// If cmp(current->data, data_ref) == 0 (i.e., data is equal to data_ref), the current node is removed.
// If the node is not the first node, we update the previous->next pointer to skip over the current node.

// If the node is the first node (previous == NULL), we update the head of the list (*begin_list).
// Memory management: After the node is removed, free(current) is called to free the memory of the current node.
// Advancing the list: If the node was removed, we move to the next node (current = previous ? previous->next : *begin_list), otherwise, we just move to the next node in the list.

//Edge Cases:
//  The list might be empty (*begin_list == NULL).
//  The node to be removed might be the first node.
//  The node to be removed might be the last node.
//  There could be multiple nodes to be removed in sequence.
