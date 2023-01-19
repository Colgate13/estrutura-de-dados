#include <stdio.h>
#include <stdlib.h>

struct ponto
{
  int x;
  int y;
};

typedef struct ponto Ponto;

struct node
{
  Ponto *p;
  struct node *next;
  int emptyNodes;
};
typedef struct node Node;

Node *create(int x, int y)
{
  Ponto *p = (Ponto *)malloc(sizeof(Ponto));
  Node *node = (Node *)malloc(sizeof(Node));

  node->p = p;
  node->p->x = x;
  node->p->y = y;
  node->next = NULL;
  node->emptyNodes = 0;

  return node;
}

Node *createNodes()
{
  Node *nodes = create(0, 0);
  nodes->emptyNodes = 1;
  return nodes;
}

void add(int x, int y, Node *node)
{ // Last in, is first in list
  if (node->emptyNodes == 1)
  {
    node->p->x = x;
    node->p->y = y;
    node->emptyNodes = 0;
  }
  else
  {
    Node *aux = node;
    while (aux->next != NULL)
    {
      if (aux == NULL)
        break;

      aux = aux->next;
    }

    aux->next = create(x, y);
  }
}

void list(Node *node)
{
  Node *aux = node;

  do
  {
    printf("X: %d | Y: %d\n", aux->p->x, aux->p->y);
    aux = aux->next;

    if (aux->next == NULL)
      printf("X: %d | Y: %d\n", aux->p->x, aux->p->y);

  } while (aux->next != NULL);
}

int main()
{

  Node *lista = createNodes();
  add(1, 2, lista);
  add(3, 4, lista);
  add(5, 6, lista);
  add(7, 8, lista);
  add(9, 10, lista);
  list(lista);

  // float a = 1;
  // printf("%p\n", (int *)&a); // () converter, aqui estamos convertendo float para um ponteiro de int
  // printf("%p\n", malloc(sizeof(Node)));
  // printf("%p\n", (int *)malloc(sizeof(Node)));
  // printf("%p", (Node *)malloc(sizeof(Node)));
  return 0;
}
