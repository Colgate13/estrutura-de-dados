#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *left;
  struct node *right;
};

typedef struct node Node;

Node *create(int value)
{
  Node *tree = (Node *)malloc(sizeof(Node));
  tree->value = value;
  tree->left = NULL;
  tree->right = NULL;

  return tree;
}

void print(Node *root, int depth)
{
  if (root == NULL)
  {
    return;
  }

  // Imprime a subarvore direita
  print(root->right, depth + 1);

  // Imprime a raiz
  for (int i = 0; i < depth; i++)
  {
    printf("   ");
  }
  printf("└──");
  printf("%d\n", root->value);

  // Imprime a subarvore esquerda
  print(root->left, depth + 1);
}

void printInOrder(Node *tree)
{
  if (tree == NULL)
    return;

  printInOrder(tree->left);
  printf("%d ", tree->value);
  printInOrder(tree->right);
}

void add(Node *tree, int value)
{
  if (tree == NULL)
  {
    tree = create(value);
    return;
  }

  if (value < tree->value)
  {
    if (tree->left == NULL)
      tree->left = create(value);
    else
      add(tree->left, value);
  }
  else
  {
    if (tree->right == NULL)
      tree->right = create(value);
    else
      add(tree->right, value);
  }
}

Node *pop(Node *tree, int value)
{
  if (tree == NULL)
    return NULL;

  if (value < tree->value)
    tree->left = pop(tree->left, value);
  else if (value > tree->value)
    tree->right = pop(tree->right, value);
  else if (value == tree->value)
  {
    if (tree->left == NULL && tree->right == NULL)
    {
      free(tree);
      return NULL;
    }

    if (tree->left != NULL && tree->right == NULL)
    {
      Node *aux = tree->left;
      free(tree);
      return aux;
    }

    if (tree->left == NULL && tree->right != NULL)
    {
      Node *aux = tree->right;
      free(tree);
      return aux;
    }

    if (tree->left != NULL && tree->right != NULL)
    {
      Node *aux = tree->right;
      while (aux->left != NULL)
      {
        aux = aux->left;
      }
      tree->value = aux->value;
      tree->right = pop(tree->right, aux->value);
      return tree;
    }
  }
  return tree;
}

int main()
{
  Node *tree = create(10);
  add(tree, 5);
  add(tree, 15);
  add(tree, 17);
  add(tree, 3);
  add(tree, 7);
  add(tree, 8);
  add(tree, 6);
  add(tree, 9);
  add(tree, 12);
  print(tree, 1);
  printf("\n");
  printf("\n");
  printInOrder(tree);
  printf("\n");
  print(tree, 1);
  printf("--------------\n");
  pop(tree, 10);
  print(tree, 1);
  printInOrder(tree);
  printf("\n");
  pop(tree, 5);
  printf("\n");
  printInOrder(tree);
  printf("\n");

  return 0;
}
