#include <iostream>
#include <cstring>
using namespace std;
int n,dp[1000000];
unsigned int maxres;
int check(int n)
{
    if (n==0)
        return 0;

   if (dp[n]!=-1)
    return dp[n];
   int res1=check(n/2);
    int res2=check(n/3);
    int res3 =check(n/4);
    return dp[n]=max(n,res1+res2+res3);
}
  int  solve(int n)
{
    if (n<1000000)
        return check(n);
   int res1=solve(n/2);
    int res2=solve(n/3);
    int res3=solve(n/4);

    return (res2+res1+res3);
}
int main()
{
    for (int i=0;i<10;i++)
{
    memset(dp,-1,sizeof dp);
    cin>>n;
       maxres= solve(n);
        cout<<maxres<<endl;
   } return 0;
}
