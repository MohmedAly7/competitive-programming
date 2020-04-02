#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std ;
int it[2001][2],n,s,res,maxret;
int vist[2003][2003];
int solve(int x,int sz)
{    if (vist[x][sz]!=-1)
        return vist[x][sz];


    if (x==n) return 0 ;
    int ret1=solve(x+1,sz);
    if (s<sz+it[x][0])return ret1 ;
    int ret2=solve(x+1,sz+it[x][0])+it[x][1];
    if (ret1>ret2)
        maxret=ret1;
    else
        maxret = ret2;
    vist[x][sz]= maxret;
     return maxret;
}


int main()

{
    memset(vist,-1,sizeof vist);
    cin>>s>>n;
    for (int i=0;i<n;i++)
    cin>>it[i][0]>>it[i][1];
   res= solve(0,0);
    cout << res<<endl;




    return 0;
}
