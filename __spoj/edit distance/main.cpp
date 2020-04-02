#include <iostream>
#include<string>
#include<cstring>
using namespace std;
string a ,b;
int memo[2001][2001];
int solve (int i,int j)
{
    if (i==a.size())
        return b.size()-j;
    if (j==b.size())
        return a.size()-i;
    if (memo[i][j]!=-1)
        return memo[i][j];
    if (a[i]==b[j])
    {
        return solve (i+1,j+1);
    }
    return memo[i][j]=min(1+solve(i+1,j+1),min(1+solve(i,j+1),1+solve(i+1,j)));

}
int t;
int main()
{
    cin>>t;
    while(t)
    {
        memset(memo,-1,sizeof memo);
        cin >>a>>b;
        cout<<solve(0,0)<<endl;
        t--;
        a.clear();b.clear();
    }

       return 0;
}
