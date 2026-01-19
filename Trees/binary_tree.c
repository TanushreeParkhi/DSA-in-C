#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

int max(int a, int b)
{
    return a>b?a:b;
}

int height(node *root)
{
    if (!root) return 0;
    return 1+max(height(root->left), height(root->right));
}

node *newnode(int val)
{
    node *new=malloc(sizeof(node));
    if (!new) exit(1);
    new->data=val;
    new->left=new->right=NULL;
    return new;
}

void inorder(node *root)
{
    if (!root) return;
    inorder(root->left);
    printf("%5d",root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (!root) return;
    printf("%5d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%5d", root->data);
}

node *insert_left(node *root, int val)
{
    if (!root) 
        return newnode(val);
    if (root->left==NULL)
    {
        root->left=newnode(val);
        return root;
    }
    insert_left(root->left, val);
    return root;
}

node *insert_right(node *root, int val)
{
    if (!root) 
            return newnode(val);
    if (root->right==NULL)
    {
        root->right=newnode(val);
        return root;
    }
    insert_right(root->right, val);
    return root;
}

int count_leaf(node *root)
{
    if (!root) return 0;
    if (root->right==NULL && root->left==NULL)
        return 1;
    return count_leaf(root->left)+count_leaf(root->right);
}

int count_total(node *root)
{
    if (!root) return 0;
    return count_total(root->left)+count_total(root->right)+1;
}

int count_nonleaf(node *root)
{
    return count_total(root)- count_leaf(root);
}



int main()
{
    node *tree=NULL;
    int ch;
    while(1)
    {
        printf("\n1.Insert left\n2.Insert right\n3.Count leaf nodes\n4. Count non-leaf nodes\n5. Count total nodes\n6. Inorder traversal\n7. Preorder traversal\n8. Postorder traversal\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        int num;
        switch(ch)
        {
            case 1:printf("Enter value to insert:");
                    scanf("%d", &num);
                    tree=insert_left(tree, num);
                    break;
            case 2:printf("Enter value to insert:");
                    scanf("%d", &num);
                    tree=insert_right(tree, num);
                    break;
            case 3:printf("No. of leaf nodes: %d\n", count_leaf(tree));
                    break;
            case 4:printf("No. of non- leaf nodes: %d\n", count_nonleaf(tree));
                    break;
            case 5:printf("Total no. of nodes: %d\n", count_total(tree));
                    break;
            case 6:inorder(tree);
                    break;
            case 7:preorder(tree);
                    break;
            case 8:postorder(tree);
                    break;
            default:exit(0);
        }
    }
    return 0;
}
