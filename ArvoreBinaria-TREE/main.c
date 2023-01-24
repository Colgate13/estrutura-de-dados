#include <stdio.h>
#include <stdlib.h>

struct node
{
  int valor;
  struct node *left;
  struct node *right;
};

typedef struct node Node;

Node *create(int valor)
{
  Node *tree = (Node *)malloc(sizeof(Node));
  tree->valor = valor;
  tree->left = NULL;
  tree->right = NULL;

  return tree;
}

void print(Node *tree)
{
  if (tree == NULL)
  {
    return;
  }

  printf("Valor: %d\n", tree->valor);
  print(tree->left);
  print(tree->right);
}

void add(Node *tree, int valor)
{
  if (valor < tree->valor)
  {
    if (tree->left == NULL)
      tree->left = create(valor);
    else
      add(tree->left, valor);
  }
  else
  {
    if (tree->right == NULL)
      tree->right = create(valor);
    else
      add(tree->right, valor);
  }
}

int main()
{
  Node *tree = create(1);
  add(tree, 2);
  add(tree, 3);
  add(tree, 4);
  print(tree);
  return 0;
}
