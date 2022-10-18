// STACK using Linked List
#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node *next;
};
typedef struct{
    struct node *top;
}STACK;
int push(STACK *s, int v)
{
    struct node *cur;
    cur=malloc(sizeof(struct node));
    if (cur==NULL)
    {
        printf("Overflow\n");
        return 1;
    }
    cur->val=v;    // a cur node is created
    cur->next=s->top;   // cur is inserted b4 top
    s->top=cur;
    return 0;
}
int pop(STACK *s,int *v)
{
    if (s->top==NULL)
    {
        printf("Underflow\n");
        return 1;
    }
    struct node *ptr=s->top;
    s->top=s->top->next;
    *v=ptr->val;
    free(ptr);
    return 0;
}
int isempty(STACK *s)
{
    if(s->top==NULL)
     return 1;
    return 0; 
}
void display(STACK s)
{
    for (; s.top!= NULL; s.top= s.top->next)
    {
        printf("%d ", s.top->val);
    }
    printf("\n");
}
void displayr(STACK *s)
{
    if(!isempty(s)){
        int d;
        pop(s,&d);
        printf("%d ",d);    
        displayr(s);
        push(s,d);
    }
}
void init(STACK *s)
{
    s->top=NULL;
}
int main(int argc, char const *argv[])
{
    STACK s1;
    init(&s1);
    int valdeleted;

    int i=1;
        printf("1: Check if the stack is empty\n");
        printf("2: Display Stack\n");
        printf("3: Push an element\n");
        printf("4: Pop an element\n");
        printf("0: Exit\n");
    while(i!=0)
    {

        printf("\nEnter the value of i\n");
        scanf("%d",&i);
        if(i==1)
        {
            if(isempty(&s1))
            {
                printf("Stack is empty\n");
            }
            else 
                printf("Stack is not empty\n");
        }
        else if(i==2)
        {
            displayr(&s1);
        }
        else if(i==3)
        {
            int j;
            printf("Enter the value to be pushed\n");
            scanf("%d",&j);
            push(&s1,j);
        }
        else if(i==4)
        {
            pop(&s1,&valdeleted);
            printf("Popped value = %d\n",valdeleted);
        }
        else if(i==0)
         printf("Exiting\n");
        else 
         printf("Invalid input\n");

    }
    return 0;
}