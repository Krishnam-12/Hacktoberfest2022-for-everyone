//BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node*left;
    int data;
    struct node*right;
};

struct node* cnode(int no)
{
    struct node *cur;
    cur=malloc(sizeof(struct node));
    cur->data=no;
    cur->left=cur->right=NULL;
    return cur;
}
struct node * maxnode(struct node* r)
{
    if(r==NULL)
     return r;
    if(r->right==NULL)
     return r;
    return maxnode(r->right); 
}
struct node * minnode(struct node* r)
{
    if(r==NULL)
     return r;
    if(r->left==NULL)
     return r;
    return minnode(r->left); 
}
struct node * search(struct node *r,int val)
{
    if (r==NULL)
     return r;
    if(val>r->data)
    {
        return search(r->right,val);
    }
    else if (val<r->data)
    {
        return search(r->left,val);
    }
    else
     return r;
}
int max(int a,int b)
{
    if(a>=b)
     return a;
    else
    return b;
}
void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}
void preorder(struct node *r)
{
    if(r!=NULL)
    {
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(struct node *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->data);
    }
}
int height(struct node *r)
{
    if(r==NULL)
     return -1;
    return max(height(r->left),height(r->right))+1;
}
struct node* insert(struct node* r,int val)
{
    if (r==NULL)
    {
        r=cnode(val);
        return r;
    }
    else if(val<r->data)
    {
        r->left=insert(r->left,val);
    }
    else if (val>r->data)
    {
        r->right=insert(r->right,val);
    }
    return r;
    
}
struct node * delete(struct node *r,int val)
{
    if(r==NULL)
     return r;
    if (val>r->data)
    {
        r->right=delete(r->right,val);
        return r;
    }
    else if (val<r->data)
    {
        r->left=delete(r->left,val);
        return r;
    }
    else        //element found
    {
        if(r->left!=NULL && r->right!=NULL) //2 child
        {
            struct node * cur= maxnode(r->left);
            r->data=cur->data;
            r->left=delete(r->left,r->data);
            return r;
        }
        else if (r->right!=NULL)
        {
            struct node * temp=r->right;
            free(r);
            return temp;
        }
        else if (r->left!=NULL)
        {
            struct node * temp=r->left;
            free(r);
            return temp;
        }
        else
        {
            free(r);
            return NULL;
        }
    }
}
int main(int argc, char const *argv[])
{
    struct node *root=NULL;
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,6);
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    preorder(root);
    printf("\nHeight = %d",height(root));
    struct node *ptr=maxnode(root);
    printf("\nMax element = %d",ptr->data);
    root=delete(root,4);
    printf("\n");
    inorder(root);
    return 0;
}