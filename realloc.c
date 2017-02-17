/*
** realloc.c for  in /home/antoine/PSU_2015_malloc
**
** Made by antoine bayard
** Login   <antoine@epitech.net>
**
** Started on  Sun Feb 14 22:11:41 2016 antoine bayard
** Last update Sun Feb 14 22:13:49 2016 antoine bayard
*/

#include <string.h>
#include "malloc.h"
#include "utils.h"

void		*realloc(void *ptr, size_t size)
{
  t_node	toResize;
  t_node	newAlloc = NULL;

  if (ptr == NULL)
    return (malloc(size));
  if (size > INT_MAX)
    size = 0;
  toResize = (t_node)(ptr - META_SIZE);
  if (size == 0)
    newAlloc = malloc(toResize->size) + 1;
  else if (toResize->size < (int)size)
    {
      if ((newAlloc = malloc(size) - META_SIZE) == NULL)
	return( NULL);
      memcpy(newAlloc + 1, toResize + 1, toResize->size);
    }
  else
    newAlloc = toResize;
  return newAlloc + 1;
}
