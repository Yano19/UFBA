#include <stdio.h>
#include <stdlib.h>

enum COLOR{
    Red, 
    Black
};

typedef struct tree_node {
    int data;
    struct tree_node *right;
    struct tree_node *left;
    struct tree_node *parent;
    enum COLOR color;
    short height;
}tree_node;

typedef struct red_black_tree{
    tree_node *root;
    tree_node *NIL;
}red_black_tree;

tree_node* new_tree_node(int data) {
    tree_node* n = malloc(sizeof(tree_node));
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->data = data;
    n->color = Red;
    n->height = 0;
    return n;
}

short max(short a, short b){
  return (a > b) ? a : b;
}

short nodeHeight(tree_node *node){
    if(node == NULL){
      return -1;
    }else{
      return(node->height);
    }
}

short fatorDeBalanceamento(tree_node *node){
  if(node){
    return (nodeHeight(node->left)) - (nodeHeight(node->right));
  }else{
    return 0;
  }
}

int altura(tree_node *root){
  if(root == NULL){
    return -1;
  }else{
    int esq = altura(root->left);
    int dir = altura(root->right);
    if(esq > dir){
      return esq + 1;
    }else{
      return dir + 1;
    }
  }
}

red_black_tree* new_red_black_tree(){
    red_black_tree *t = malloc(sizeof(red_black_tree));
    tree_node *nil_node = malloc(sizeof(tree_node));
    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->parent = NULL;
    nil_node->color = Black;
    nil_node->data = 0;
    t->NIL = nil_node;
    t->root = t->NIL;

  return t;
}

void left_rotate(red_black_tree *t, tree_node *x) {
  tree_node *y = x->right;
  x->right = y->left;
  if(y->left != t->NIL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == t->NIL) { //x is root
    t->root = y;
  } else if(x == x->parent->left) { //x is left child
    x->parent->left = y;
  } else { //x is right child
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
  x->height = max(nodeHeight(x->left), nodeHeight(x->right)) + 1;
  y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;
}

void right_rotate(red_black_tree *t, tree_node *x) {
  tree_node *y = x->left;
  x->left = y->right;
  if(y->right != t->NIL) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == t->NIL) { //x is root
    t->root = y;
  }
  else if(x == x->parent->right) { //x is left child
  x->parent->right = y;
  } else { //x is right child
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
  x->height = max(nodeHeight(x->left), nodeHeight(x->right)) + 1;
  y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;
}

void insertion_fixup(red_black_tree *t, tree_node *z) {
while(z->parent->color == Red) {
  if(z->parent == z->parent->parent->left) { //z.parent is the left child

    tree_node *y = z->parent->parent->right; //uncle of z

    if(y->color == Red) { //case 1
      z->parent->color = Black;
      y->color = Black;
      z->parent->parent->color = Red;
      z = z->parent->parent;
    }
    else { //case2 or case3
      if(z == z->parent->right) { //case2
        z = z->parent; //marked z.parent as new z
        left_rotate(t, z);
      }
      //case3
      z->parent->color = Black; //made parent black
      z->parent->parent->color = Red; //made parent red
      right_rotate(t, z->parent->parent);
    }
  }
  else { //z.parent is the right child
    tree_node *y = z->parent->parent->left; //uncle of z

    if(y->color == Red) {
      z->parent->color = Black;
      y->color = Black;
      z->parent->parent->color = Red;
      z = z->parent->parent;
    }
    else {
      if(z == z->parent->left) {
        z = z->parent; //marked z.parent as new z
        right_rotate(t, z);
      }
      z->parent->color = Black; //made parent black
      z->parent->parent->color = Red; //made parent red
      left_rotate(t, z->parent->parent);
    }
  }
}
t->root->color = Black;
}

void insert(red_black_tree *t, tree_node *z) {
    tree_node* y = t->NIL; 
    tree_node* temp = t->root;

    while(temp != t->NIL) {
        y = temp;
        if(z->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

z->parent = y;

if(y == t->NIL) { 
  t->root = z;
  } else if(z->data < y->data)
    y->left = z;
  else
    y->right = z;

  z->right = t->NIL;
  z->left = t->NIL;
  z->height = max(nodeHeight(z->left), nodeHeight(z->right) + 1);
  insertion_fixup(t, z);
}


void inorder(red_black_tree *t, tree_node *n, int level) {
if(n != t->NIL) {
  inorder(t, n->left, level + 1);
  printf("\n\n");
  for(int i = 0; i < level; i++){
    printf("\t");
  }
  printf("%d ", n->data);
  inorder(t, n->right, level + 1);
}
}


int main() {
red_black_tree *t = new_red_black_tree();
int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13;
tree_node *node;
tree_node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;
printf("\nDigite o valor que deseja inserir: \n");
scanf("%d\n", &d0);
scanf("%d\n", &d1);
scanf("%d\n", &d2);
scanf("%d\n", &d3);
scanf("%d\n", &d4);
scanf("%d\n", &d5);
scanf("%d\n", &d6);
scanf("%d\n", &d7);
scanf("%d\n", &d8);
scanf("%d\n", &d9);
scanf("%d\n", &d11);
scanf("%d\n", &d12);
scanf("%d\n", &d13);

a = new_tree_node(d1);
b = new_tree_node(d2);
c = new_tree_node(d3);
d = new_tree_node(d4);
e = new_tree_node(d5);
f = new_tree_node(d6);
g = new_tree_node(d7);
h = new_tree_node(d8);
i = new_tree_node(d9);
j = new_tree_node(d10);
k = new_tree_node(d11);
l = new_tree_node(d12);
m = new_tree_node(d13);

insert(t, a);
insert(t, b);
insert(t, c); 
insert(t, d);
insert(t, e);
insert(t, f);
insert(t, g);
insert(t, h);
insert(t, i);
insert(t, j);
insert(t, k);
insert(t, l);
insert(t, m);

inorder(t, t->root, 1);
printf("\na altura: %d\n", t->root->height);
printf("\na altura: %d\n", altura(t->root));
  return 0;
}