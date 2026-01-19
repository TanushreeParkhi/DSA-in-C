#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}node;

node *newnode(int val)
{
    node *new=malloc(sizeof(node));
    if (!new) exit(1);
    new->data=val;
    new->left=new->right=NULL;
    return new;
}

node *insert(node *root, int val)
{
    if (!root) return newnode(val);
    if (root->data>val)
    {    root->left=insert(root->left, val);
    }
    else if (root->data<val)
    {    root->right=insert(root->right, val);
    }
    return root;   
}

node *MIN(node *root)
{
    if (!root) return root;
    if (root->left==NULL) return root;
    return MIN(root->left);

}

node *delete(node *root, int val)
{
    if (!root) return root;

    if (root->data>val)
        root->left=delete(root->left, val);
    else if (root->data<val)
        root->right=delete(root->right,val);
    else{
        if (root->right==NULL && root->left==NULL)
        {    free(root);
            return NULL;
        }
        else if (root->left==NULL || root->right==NULL)
        {
            node *temp;
            if (!root->left) temp=root->right;
            else temp=root->left;
            free(root);
            return temp;
        }

        else{
            node *temp=MIN(root->right);
            root->data=temp->data;
            root->right=delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%5d", root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root)
    {
        printf("%5d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%5d", root->data);
    }
}

int main()
{
    node *tree=NULL;
    int ch, num;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\nEnter choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter num to insert:");
                    scanf("%d", &num);
                    tree=insert(tree, num);
                    break;
            case 2: printf("Enter num to delete:");
                    scanf("%d", &num);
                    tree=delete(tree, num);
                    break;  
            case 3: inorder(tree);
                    break;
            case 4: preorder(tree);
                    break;
            case 5: postorder(tree);
                    break;
            default: exit(0);    
        }
    }
}

