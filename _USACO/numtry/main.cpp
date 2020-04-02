/*
ID: m.a.lea1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include<algorithm>
#include <cstring>
#include<stdio.h>
using namespace std;
FILE * in = fopen("numtri.in","r");
FILE * out = fopen("numtri.out","w");

int arr[1000][1000],vist[1001][1001];
int res,mres,r;
int solve(int x , int y )
    {
        if (vist[x][y]!=-1)return vist[x][y];
        if (x==r)return 0;
         int res1=solve (x+1,y+1)+arr[x][y];
        int res2=solve (x+1,y)+arr[x][y];
        return vist[x][y]= max(res1,res2);
    }
int main()
{

    fscanf(in,"%d",&r);
    memset(vist,-1,sizeof vist);
    for (int i=0;i<r;i++)
        for (int j=0;j<=i;j++)
           fscanf(in,"%d",&arr[i][j]) ;
          mres= solve(0,0);
            fprintf(out,"%d\n",mres);

    return 0;
}
