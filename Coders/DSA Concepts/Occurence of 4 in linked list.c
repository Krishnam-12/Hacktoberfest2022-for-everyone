// WAP to count the number of occurrences of an element in a linked list of n nodes.
#include <stdio.h>
#include <stdlib.h>
struct node //declaring data type
{
    int data;
    struct node *next;
};
void create(struct node **h)
{    
     struct node *cur,*ptr;
     cur=malloc(sizeof(struct node));
     cur->data=rand()%10;
     cur->next=NULL;
     if (*h==NULL)
     {
          *h=cur;
          ptr=*h;
     }
     else
     {
          ptr->next=cur;
          ptr=cur;    
     }    
}
void display(struct node *h)
{
     for ( ; h!=NULL; h=h->next)
     {
          printf("%d ",h->data);
     }     
}
int count(struct node *h,int val)
{
    struct node *ptr; int occur=0;
    for(ptr=h; ptr!=NULL;ptr=ptr->next)
    {
        if (ptr->data==val)
        {
            occur++;
        }
    }    
    return occur;
}

int main(int argc, char const *argv[])
{
    int n,val;
    struct node *head = NULL;
    printf("\nEnter number of nodes to be created \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) //creating linked list
    {         
         create(&head);
    }
    display(head);
    printf("\n4 occured %d time in the given linked list",count(head,4));

    return 0;
}
