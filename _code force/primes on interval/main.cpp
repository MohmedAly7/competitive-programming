#include <iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
bool prime[1000001]={true};
int a,b,k,l,mid,ans=10000000,p=1,sum[1000001];
bool check (int l)
{

    int i;
    for(i=a ;i+l <= b+1;i++)
        if(sum[i+l-1] - sum[i-1] < k) return 0;
    return 1;
}
int solve (int a,int b)
{
    if (a>b) return mid;
    mid =(a+b)/2;
    if (check(mid)){
            ans=min(mid,ans);
        return solve (a,mid-1);}
    else return solve (mid+1,b);


}
int main()
{
    memset(prime,1,sizeof prime);
    prime[0]=0,prime[1]=0;
    for (int i=2;i<1000001;i++)
 {
       if (prime[i])
    {
        for(int j=i+i;j<1000001;j=j+i)
            prime[j]=0;
    }

 }
 for (int i=2;i<1000001;i++)
    sum[i]=sum[i-1]+prime[i];

    scanf("%d %d %d",&a,&b,&k);
    solve(1,b-a+1);
    if (ans<=b-a+1)
    printf("%d",ans);
    else
    printf("-1");
    return 0;
}
