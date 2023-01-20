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
  struct node *head;
  int emptyNodes;
};
typedef struct node Node;

struct list
{
  Node *nodes;
  Node *headNode;
};

typedef struct list List;

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

List *createNodes()
{
  List *list = (List *)malloc(sizeof(List));
  Node *nodes = create(0, 0);
  nodes->emptyNodes = 1;
  nodes->emptyNodes = 1;

  list->nodes = nodes;
  list->headNode = nodes;
  return list;
}

void add(int x, int y, List *list)
{
  if (list->nodes->emptyNodes == 1)
  {
    list->nodes->p->x = x;
    list->nodes->p->y = y;
    list->nodes->emptyNodes = 0;
    list->headNode = list->nodes;
  }
  else
  {
    Node *aux = list->nodes;
    while (aux->next != NULL)
    {
      if (aux == NULL)
        break;

      aux = aux->next;
    }

    aux->next = create(x, y);
  }
}

void list(List *list)
{
  Node *aux = list->headNode;

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

  List *lista = createNodes();
  float forLong = 1e4;
  for (float i = 0; i < forLong; i++)
  {
    add((int)i, (int)i + 1, lista);
  }
  list(lista);

  // float a = 1;
  // printf("%p\n", (int *)&a); // () converter, aqui estamos convertendo float para um ponteiro de int
  // printf("%p\n", malloc(sizeof(Node)));
  // printf("%p\n", (int *)malloc(sizeof(Node)));
  // printf("%p", (Node *)malloc(sizeof(Node)));
  return 0;
}
