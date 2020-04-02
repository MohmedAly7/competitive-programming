#include <iostream>
#include<cstring>
using namespace std;
int memo[2001][2001],arr[2001],n;
int solve(int ind,int x)
{
    if (x>n) return 0;
    if (memo[ind][x]!=-1) return memo[ind][x];
    int ret=solve(ind+1,x);
    if (arr[ind]>arr[x])
         ret=max(1+solve(ind+1,ind),ret);
         return ret;
}
int main()
{
    cin >>n;
    memset(memo,-1,sizeof memo);
    arr[0]=-1;
    for (int i=1; i<=n;i++)
        cin>>arr[i];
        cout<<solve(1,0);
    return 0;

}
