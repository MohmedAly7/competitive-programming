#include <iostream>
#include<stdio.h>

using namespace std;
int arr1[10001],arr2[10001],n,x,y;
int main()
{   int k,l;
    for (int i=0,k=0,l=0;i<20000;i++ )
        {
            arr1[k++]=i;
            arr1[k++]=++i;
            arr2[l++]=++i;
            arr2[l++]=++i;
        }
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d", &x, &y);
        if (x==y)
            printf("%d\n",arr1[y]);
        else if (y==x-2)
            printf("%d\n",arr2[y]);
        else
            printf("No Number\n");
    }


    return 0;
}
