/*
** show_alloc_mem.c for  in /home/antoine/PSU_2015_malloc
**
** Made by antoine bayard
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 11 13:38:27 2016 antoine bayard
** Last update Sun Feb 14 21:42:11 2016 antoine bayard
*/

#include <stdio.h>
#include <assert.h>
#include "utils.h"

void	*initHeap()
{
  static void *initialHeap = NULL;

  if (initialHeap == NULL)
    {
      initialHeap = sbrk(0);
      assert(initialHeap != (void*)-1);
    }
  return initialHeap;
}

void		show_alloc_mem(void)
{
  t_node	first;
  void		*currentOffset;

  currentOffset = sbrk(0);
  assert(currentOffset != (void*)-1);
  first = *getAllocList();
  printf("break : %p\n", currentOffset);
  printf("%p - %p : %ld bytes\n", initHeap(), currentOffset, (size_t)(currentOffset - initHeap()));
  while (first != NULL)
    {
      printf("alloc size : %d\n%s\n\n", first->size, (first->isFree ? "free" : "non free"));
        first = first->next;
    }
}
