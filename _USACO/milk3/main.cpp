/*
ID: m.a.lea1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
FILE * in = fopen("milk3.in","r");
FILE * out = fopen("milk3.out","w");
int memo[20][20][20],milk[3],arr[3],ans[20],i;
void ss(int a,int b ,int c )
{
    if(memo[a][b][c]!=-1)
        return;
    if(a==0)
        ans[i++]=c;
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (i!=j){
                arr[0]=a;arr[1]=b;arr[2]=c;
                int re=milk[i]-arr[i];
                if (re>arr[j])
                {arr[i]=arr[j]+arr[i];
                    arr[j]=0;
                }else
                {arr[i]+=re;
                arr[j]-=re;
                }memo[a][b][c]=c;
                ss(arr[0],arr[1],arr[2]);
            }}}return;
}

int main()
{
    memset(memo,-1,sizeof memo);
    for(int k =0;k<3;k++)
    fscanf(in,"%d",&milk[k]);
    ss(0,0,milk[2]);
    sort(ans,ans+i);
    int k;
    for( k =0;k<i-1;k++)
        fprintf(out,"%d ",ans[k]);
        fprintf(out,"%d\n",ans[k]);
    return 0;
}
