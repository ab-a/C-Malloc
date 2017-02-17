/*
** malloc.h for in /home/antoine/PSU_2015_malloc
**
** Made by antoine bayard
** Login   <antoine@epitech.net>
**
** Started on  Thu Jan 28 15:43:04 2016 antoine bayard
** Last update Thu Jan 28 17:09:38 2016 antoine bayard
*/

#pragma once
#include <stdlib.h>

void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);

