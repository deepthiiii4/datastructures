#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int value;
    struct node* right;
    struct node* left;

};

struct node* createnode(int value)

{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

struct node* insert(struct node* root , int value)
{
    if (root == NULL)
    {
        return createnode(value);
    }
    if( value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else 
    {
         root->right = insert(root->right, value);

    }
    return root;
}

void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t" , root->value);
        inorder(root->right);

    }
}


void preorder(struct node* root)
{
    if (root!= NULL)
    {
        
        printf("%d\t" , root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root != NULL)
    {
    
        postorder(root->left);
        postorder(root->right);
        printf("%d\t" ,  root->value);

    }
}
int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 60);
    

    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("preorder: ");
    preorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");



    return 0;
    

}
