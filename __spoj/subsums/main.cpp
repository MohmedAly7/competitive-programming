#include <iostream>
#include<algorithm>

using namespace std;
int sum1[131100],sum2[131100],num1[18],num2[18],n,a,b,cnt1,cnt2;
long long ans;
bool flag;
void solve (int i,int sum)
{
    if (i>=n/2&&!flag) {
        sum1[cnt1++]=sum;
        return;
    }else if(i>n/2)
    {
        sum1[cnt1++]=sum;
        return;
    }
    solve(i+1,sum);
    solve(i+1,sum+num1[i]);
    return;
}
void solve1 (int i,int sum)
{
    if (i>=n/2) {
        sum2[cnt2++]=sum;
        return;
    }
    solve1(i+1,sum);
    solve1(i+1,sum+num2[i]);
    return;
}
int main()
{
 cin>>n>>a>>b;
 int i;
 for(i=0;i<n/2;i++)
 {
     cin>>num1[i]>>num2[i];
 }
if (n%2==1)
{cin>>num1[i];
    flag=1;
}
solve(0,0);
solve1(0,0);
  sort (sum1,sum1+cnt1);
  sort(sum2,sum2+cnt2);
  for (int j=0;j<cnt1;j++)
  if(0<(upper_bound(sum2,sum2+cnt2,b-sum1[j])-lower_bound(sum2,sum2+cnt2,a-sum1[j])))
    ans+=(upper_bound(sum2,sum2+cnt2,b-sum1[j])-lower_bound(sum2,sum2+cnt2,a-sum1[j]));
  cout<<ans;


    return 0;
}
