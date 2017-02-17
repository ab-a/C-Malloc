/*
** malloc.c for  in /home/antoine/PSU_2015_malloc
**
** Made by antoine bayard
** Login   <antoine@epitech.net>
**
** Started on  Thu Jan 28 14:07:58 2016 antoine bayard
** Last update Sun Feb 14 22:12:42 2016 antoine bayard
*/

#include "malloc.h"
#include "utils.h"

static t_node	new_block(t_node allocList, int size)
{
  t_node	newNode;

  newNode = sbrk(0);
  if (sbrk(size + META_SIZE) == (void *)-1)
    return NULL;
  newNode->next = NULL;
  newNode->prev = getLast(*getAllocList());
  newNode->size = size;
  newNode->isFree = 1;
  if (*getAllocList() == NULL)
    *getAllocList() = newNode;
  else
    getLast(allocList)->next = newNode;
  return (newNode);
}

void		*malloc(size_t size)
{
  t_node	retNode = NULL;

  initHeap();
  if (size > (INT_MAX))
    return (NULL);
  if (size == 0)
    return (NULL);
  if ((retNode = find_free_node(*getAllocList())) != NULL);
  else
    if ((retNode = new_block(*getAllocList(), (int)size)) == NULL)
      return (NULL);
  shrinkNode(retNode, (int)size);
  retNode->isFree = 0;
  return (retNode + 1);
}
