#include <iostream>
#include<cstring>
using namespace std;
string arr1,arr2;
int memo[20][20];
int solve (int ind1,int ind2)
{
    if (memo[ind1][ind2]!=-1) return memo[ind1][ind2];
    int ret =0,ret2=0;
    if (ind1==arr1.size()||ind2==arr2.size())
    return 0;
    if (arr1[ind1]==arr2[ind2])
      ret= 1+ solve (ind1+1,ind2+1);
    if (arr1[ind1]!=arr2[ind2])
    ret2=max(solve(ind1+1,ind2),solve(ind1,ind2+1));
    return memo[ind1][ind2]=max(ret,ret2);
}

int main()
{
    memset(memo,-1,sizeof memo);
    arr1[0]='a',arr2[0]='a';
    cin >>arr1>>arr2;
   cout<< solve(0,0);
       return 0;
}
