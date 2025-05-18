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
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *tmp;
    
    // Step 1: Remove matching nodes at the head
    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }

    // Step 2: Traverse the list and remove matching nodes
    t_list *current = *begin_list;
    while (current && current->next)
    {
        if (cmp(current->next->data, data_ref) == 0)
        {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else
        {
            current = current->next;
        }
    }
}

//Edge Cases:
//  The list might be empty (*begin_list == NULL).
//  The node to be removed might be the first node.
//  The node to be removed might be the last node.
//  There could be multiple nodes to be removed in sequence.
