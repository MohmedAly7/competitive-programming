#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int cow[100000],n,c,ans=0,t;
bool check (int m)
{
    int i,j,k=1;
    for (i=0;i<n;i=j)
        for(j=i;j<n;j++){
        if(cow[j]-cow[i]<m)continue;
        k++;
        break;
        }
        if(k<c)
            return 0;
    return 1;
}
int solve (int a,int b)
{
    if(a>b) return ans;
    int mid =(a+b)/2;
    if (check(mid))
    {
        ans=max(mid,ans);
        return solve(mid+1,b);
    }else return solve(a,mid-1);
}

int main()
{
    scanf("%d",&t);
    while(t)
    {
        scanf("%d%d",&n,&c);
        for(int i=0;i<n;i++)
        {
            int l;
            scanf("%d",&l);
            cow[i]=l;
        }
        sort(cow,cow+n);
        cout<<solve (0,cow[n-1])<<endl;
        t--;
        ans=0;
    }

    return 0;
}
