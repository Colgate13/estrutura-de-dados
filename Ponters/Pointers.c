#include <stdio.h>
#include <stdlib.h>

struct ponto
{
  float x;
  float y;
};

typedef struct ponto Ponto;

int main()
{
  // malloc = o malloc vai fazer com o alloc na memoria heap
  Ponto *p = (Ponto *)malloc(sizeof(Ponto));
  p->x = 1;
  p->y = 2;

  printf("X = %.0f | Y = %.0f", p->x, p->y);
  // int a = 2;
  // int *ponteiro2 = &a;
  // printf("%d", *ponteiro2);
  // printf("%p", &ponteiro2);
  // printf("%c", *p);
  return 0;
}
