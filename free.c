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
#include <stdio.h>
#include "utils.h"

static t_node	fusionToNext(t_node node)
{
  t_node	next;

  next = node->next;
  if (next->next != NULL)
    next->next->prev = node;
  node->next = next->next;
  node->size += next->size + META_SIZE;
  return node;
}

static void	releaseHeap()
{
  t_node	last = getLast(*getAllocList());
  void		*heapOffset = NULL;

  if (last == NULL)
    return ;
  while (last && last->isFree)
    {
      heapOffset = last;
      last = last->prev;
    }
  if (heapOffset != NULL)
    {
      if (((t_node)heapOffset)->prev != NULL)
	((t_node)heapOffset)->prev->next = NULL;
      if (((t_node)heapOffset)->prev != NULL)
	((t_node)heapOffset)->prev->next = NULL;
      if (heapOffset == *getAllocList())
	*getAllocList() = NULL;
      if (brk(heapOffset) == -1)
	perror("Error: ");
    }
}

static void	frag()
{
  t_node	itNode;

  itNode = *getAllocList();
  while (itNode->next != NULL)
    {
      if (itNode->isFree && itNode->next->isFree)
	fusionToNext(itNode);
      else
	itNode = itNode->next;
    }
}

void		free(void *alloc)
{
    t_node	toFree;

    if (alloc == NULL)
        return ;
    toFree = ((t_node)alloc) - 1;
    toFree->isFree = 1;
    frag();
    releaseHeap();
}
