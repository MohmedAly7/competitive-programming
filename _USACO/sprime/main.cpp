/*
ID: m.a.lea1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
FILE * in = fopen("sprime.in","r");
FILE * out = fopen("sprime.out","w");
int inp,ans[200000],cnt=0;
int first[]={2,3,5,7};
int second []={1,2,3,5,7,9};
bool check(int num)
{
    for (int i=2;i*i<=num;i++)
    {
       if (num%i==0) return 0;
    }
    return 1;
}
void solve (int di,int n)
{
    if (di>=inp)
    {
        if(check(n)&&di==inp)
            ans[cnt++]=n;
        return;
    }
    for (int i=0;i<6;i++)
    {
        int tem=n;
        tem*=10;
        tem+=second[i];
        if (check(tem))
            solve(di+1,tem);
    }
}
int main()
{
    fscanf(in,"%d",&inp);
    for (int i=0;i<4;i++)
        solve(1,first[i]);
    sort(ans,ans+cnt);
    for(int i=0;i<cnt;i++)
        fprintf(out,"%d\n",ans[i]);
        return 0;
}
