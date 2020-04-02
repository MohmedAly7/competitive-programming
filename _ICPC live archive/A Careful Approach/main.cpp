#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
pair<int,int> plane[8];
int n,ans,caseID = 0;
bool check (int m)
{
    int s ,e,k=1,pre=plane[0].first;
    for (int i=1;i<n;i++)
    {
        s=plane[i].first;e=plane[i].second;
        if (pre+m>s&&pre+m<=e)
        {
            pre=pre+m;
        }
       else if (pre+m<=s)
        {
            pre=s;
        }else return 0 ;
    }return 1;
}
int solve (int a,int b)
{
    int ret=0;
    while (a<=b)
    {
        int mid =(a+b)/2;
        if (check(mid))
        {
            a=mid+1; ret=max(ret,mid);
        }else
        b =mid-1;
    }
    return ret ;
}
int main()
{
    cin>>n;
    while(n)
    {
        memset(plane,0,sizeof plane);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&plane[i].first,&plane[i].second);
           plane[i].first *= 60000; //convert the minutes into millisecond.
            plane[i].second *= 60000;
        }
        sort (plane,plane+n);
       do
        {
            ans =max(ans,solve(1,1440*60000));
        } while(next_permutation(plane,plane+n));
        int secs = round( (double)ans / 1000.0 ); //round to closest second from milliseconds.
        int mins = secs / 60;
        secs %= 60;
        printf("Case %d: %d:%02d\n",++caseID,mins,secs);
        ans=0;
        cin>>n;
    }

    return 0;
}
