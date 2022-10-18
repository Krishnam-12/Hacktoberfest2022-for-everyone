#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    printf("Enter size of array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%100;
    }
    int min,max=arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\nSmallest = %d\n",min);
    printf("Largest = %d",max);
    
    
    return 0;
}