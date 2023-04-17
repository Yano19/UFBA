#include <stdio.h>
#include <stdlib.h>

typedef enum{
    RED,
    BLACK
}nodeColor;

typedef struct rbnode{
    int data;              // data
    nodeColor color;             // 1-red, 0-black
    struct rbnode *parent; // parent
    struct rbnode *right;  // right-child
    struct rbnode *left;   // left child
    short height;
} rbNode;

rbNode *root = NULL;

rbNode *newNode(int x){
    rbNode *new = malloc(sizeof(rbNode));
    if (new)
    {
        new->data = x;
        new->left = NULL;
        new->right = NULL;
        new->parent = NULL;
        new->color = RED;
        new->height = 0;
    }
    else
    {
        printf("\nEROO ao alocar um novo NO!\n");
    }
    return new;
}

short max(short a, short b)
{
    return (a > b) ? a : b;
}

short nodeHeight(rbNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        return (node->height);
    }
}

rbNode *insert(rbNode *root, rbNode value){
    
    if (root == NULL){
        return newNode(value);
    }else{
        if (value < root->data)        {
            root->left = insert(root->left, value);
            root->left->parent = root;
        }
        else if(value > root->data)        {
            root->right = insert(root->right, value);
            root->right->parent = root;
        }
    }
    fixup(root, value);
}

void rightRotate(rbNode *value){
    rbNode *l = value->left;
    value->left = l->right;
    if (value->left)
        value->left->parent = value;
    value->parent = value->parent;
    if (value->parent == NULL)
        root = l;
    else if (value == value->parent->left)
        value->parent->left = l;
    else
        value->parent->right = l;
    l->right = value;
    value->parent = l;
}

void leftRotate(rbNode *value)
{
    rbNode *r = value->right;
    value->right = r->left;
    if (value->right)
        value->right->parent = value;
    r->parent = value->parent;
    if (!value->parent)
        root = r;
    else if (value == value->parent->left)
        value->parent->left = r;
    else
        value->parent->right = r;
    r->left = value;
    value->parent = r;
}

void fixup(rbNode *root, rbNode *value)
{
      while (value->color == RED){
        if (value->parent == value->parent->parent->left){
            //case 1
            rbNode *uncle_pt = value->parent->parent->right;
            if (uncle_pt->color == RED){
                value->parent->color = BLACK;            
                value->parent->color = RED;
                uncle_pt->color = BLACK;
                value = value->parent->parent;
            }
            else{
                //case 2
                if (value == value->parent->right){
                    leftRotate(value->parent);
                    value = value->parent;
                    value->parent = value->parent;
                }
                //case 3
                value->parent->color = BLACK;
                value->parent->parent->color = RED;
                rightRotate(value->parent->parent);
            }
        } else {
            rbNode *uncle_pt = value->parent->parent->left;
            if (uncle_pt->color == RED){
                value->parent->parent->color = RED;
                value->parent->color = BLACK;
                uncle_pt->color = BLACK;
                value = value->parent->parent;
            }
            else{
                if (value == value->parent->left){
                    value = value->parent;
                    rightRotate(value->parent);
                    value->parent->parent = value->parent;
                }
                value->parent->color = BLACK;
                value->parent->parent->color = RED;
                leftRotate(value->parent->parent);
                value = value->parent;
            }
        }
    }
    root->color = BLACK;
}

void imprimir(rbNode *node, int level){
    if (node == NULL){
        return;
    }else{
        imprimir(node->left, level + 1);
        printf("\n\n");
        for (int i = 0; i < level; i++)
        {
            printf("\t");
        }
        printf("%d ", node->data);
        imprimir(node->right, level + 1);
        return;
    }
}

int main()
{
    int option, data;
    do
    {
        printf("1. Insertion\t2. Deletion\n");
        printf("3. Traverse\t0. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the element to insert:");
            scanf("%d", &data);
            for(int i  = 0; i < data; i++){
            rbNode *temp = malloc(sizeof(rbNode));
            temp->right = NULL;
            temp->left = NULL;
            temp->parent = NULL;
            temp->data = data;
            temp->color = RED;
            root = insert(root, data);
            fixup(root, temp);
            }
            break;
        case 2:
            printf("Enter the element to delete:");
            scanf("%d", &data);
            // root = deletion(root, data);
            break;
        case 3:
            imprimir(root, 1);
            printf("\n");
            break;
        default:
            printf("Not available\n");
        }
    } while (option != 0);
    return 0;
}