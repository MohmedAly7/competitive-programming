#include <iostream>
#include<vector>
#include<set>
#include<stdio.h>
using namespace std;
int arr[10001],ans[10001];
int n,m,k;
bool take[10001];
vector<int> arng[10001],before[10001];
set<int>ma;
int main()
{
    cin >>n>>m;
    while(m)
    {int x,y;
    scanf("%d %d",&x,&y);
    arng[x].push_back(y);
    arr[y]++;
    m--;
    }
    for(int i=1;i<=n;i++)
    {
        if (!arr[i]&&!take[i])
        {
           ma.insert(i);
            take[i]=1;
        }
    }
    while (ma.size())
    {
        int tem=*ma.begin();
        ma.erase(ma.begin());
          for(int j=0;j<arng[tem].size();j++)
            {
                arr[arng[tem][j]]--;
                if (!arr[arng[tem][j]])
                    {
                    ma.insert(arng[tem][j]);
                    take[arng[tem][j]]=1;
                    }
            }
        ans[k++]=tem;
    }

        if (n==k)
        for (int h=0;h<n;h++)
            printf("%d ",ans[h]);
        else
            cout<<"Sandro fails.";
            cout<<endl;
    return 0;
}
