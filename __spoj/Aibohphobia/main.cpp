#include <iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n,dp[6101][6101],maxres;
string ch;
int solve(int x ,int y)
{
    if (x>=y)
        return 0;
    if(dp[x][y]!=-1)
    return dp[x][y];

    if (ch[x]==ch[y])
        return dp[x][y]= solve(x+1,y-1);
           return dp[x][y]=min(1+solve(x+1,y),1+solve(x,y-1));
}
int main()
{
    cin>>n;
    while(n>0){
    n=n-1;
    memset(dp,-1,sizeof dp);
    cin>>ch;

   maxres =solve(0,ch.size() -1);
   cout <<maxres<<endl;
    }return 0;
}
