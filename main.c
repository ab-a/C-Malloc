#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"
#include "utils.h"

int	main()
{
/*  char   *buf[1000];
  char	*buf2[1000];
  char	*buf3[1000];

  int i = 0;
  while (i < 1000)
    {
      buf[i] = malloc(10);
      buf2[i]  = malloc(10);
      buf3[i] = malloc(10);
      i++;
    }
  i = 300;
  while (i < 600)
    {
      memset(buf2[i], 'A', 10);
      buf2[i] = realloc(buf2[i], 20);
      memset(buf2[i] + 10, 'Z', 10);
      memset(buf2[i] + 10, 'Z', 10);
      buf3[i] = realloc(buf3[i], 20);
      memset(buf2[i] + 10, 'Z', 10);
      free(buf2[i]);
      free(buf3[i]);
      i++;
    }
  while (i < 1000)
    {
      memset(buf[i], 'A', 10);
      buf[i] = realloc(buf[i], 20);
      memset(buf[i] + 10, 'Z', 10);
      buf[i][19] = 0;
      printf("%s\n", buf[i]);
      i++;
    }
  i = 999;
  while (i > 5)
    {
      free(buf[i]);
      i--;
    }
show_alloc_mem();
  return (0);
*/

    void *buf1 = malloc(5);
    free(buf1);
    void *buf2 = malloc(568);
    void *buf3 = realloc(NULL, 1600);
    void *buf4 = realloc(NULL, 1024);
    buf4 = realloc(buf4, 2048);
    free(buf2);
    free(NULL);
    void *buf5 = malloc(5);
    free(buf5);
    void *buf6 = malloc(45);
    free(buf6);
}
