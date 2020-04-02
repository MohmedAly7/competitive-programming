#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
pair<int,int>tim[202];
int t,n,m,me,cnt,mcnt;
int main()
{
    cin>>t;
    while(t)
    {
    cin>>n;
    memset(tim,-1,sizeof tim);
    for (int i=0;i<n*2;i++)
    {
        int x,y;
        cin>>x;
        tim[i].first=x;
        tim[i++].second=1;
        cin >>y;
        tim[i].first=y;
        tim[i].second=0;
       me= max(me,y);
    }
    sort(tim,(tim+(n*2+1)));
    for (int i=0;i<n*2+1;i++)
        if (tim[i].second!=-1)
    {
        if (tim[i].second==1)
            cnt++;
        if(tim[i].second==0)
            cnt--;
        mcnt=max(mcnt,cnt);
    }
    cout<<mcnt<<endl;
    mcnt=0;
    t--;
    }
    return 0;
}
