/*
** free.c for  in /home/antoine/PSU_2015_malloc
**
** Made by antoine bayard
** Login   <antoine@epitech.net>
**
** Started on  Sun Feb 14 22:12:57 2016 antoine bayard
** Last update Sun Feb 14 22:13:26 2016 antoine bayard
*/

#include <stdlib.h>
#include "utils.h"
#include "malloc.h"

t_node  *getAllocList(void)
{
    static  t_node allocList = NULL;
    
    return &allocList;
}

t_node  find_free_node(t_node firstNode)
{
    while (firstNode != NULL) {
        if (firstNode->isFree)
            return (firstNode);
        firstNode = firstNode->next;
    }
    return (NULL);
}

t_node	shrinkNode(t_node node, int size)
{
    t_node  newShrink;

    if (node->size < size + (int)(META_SIZE + 20))
      return node;
    newShrink = (void *)(node + 1) + size;
    newShrink->next = node->next;
    newShrink->prev = node;
    node->next = newShrink;
    newShrink->size = node->size - size - META_SIZE;
    node->size = size;
    return node;
}

t_node getLast(t_node allocList)
{
    if (allocList == NULL) {
        return NULL;
    }
  while (allocList->next != NULL)
    allocList = allocList->next;
  return (allocList);
}
