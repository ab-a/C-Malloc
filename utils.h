/*
** utils.h for  in /home/antoine/PSU_2015_malloc
**
** Made by antoine bayard
** Login   <antoine@epitech.net>
**
** Started on  Sun Feb 14 22:12:12 2016 antoine bayard
** Last update Sun Feb 14 22:12:14 2016 antoine bayard
*/

#pragma once

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "malloc.h"

#define META_SIZE sizeof(struct s_node)

typedef struct s_node * t_node;

struct s_node {
  int       size;
  int       isFree;

  t_node next;
  t_node prev;
};

t_node  *getAllocList(void);
t_node  find_free_node(t_node);
t_node	shrinkNode(t_node node, int size);
t_node	getLast(t_node allocList);
void	*initHeap();
void	show_alloc_mem();
