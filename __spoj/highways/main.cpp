#include <iostream>
#include<vector>
#include <set>
#include<algorithm>
#include <stdio.h>
#include<cstring>
using namespace std;
int arr[100001];
int c,sc,ec,m,nc;
class node
{
public:
    int s ,e,cost;
};
bool operator < (node a ,node b)
{
    if(a.cost != b.cost) return a.cost < b.cost;
    if (a.s<b.s) return 1;
    if (a.e<b.e) return 1;
    return 0;
}
node t;
set<node> ready;
vector<node> edge[100001];
int main()
{
    scanf("%d",&c);
    while (c)
    {
        scanf("%d%d%d%d",&nc,&m,&sc,&ec);
        if (sc>ec)
            swap(sc,ec);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&t.s,&t.e,&t.cost);
            if(t.s>t.e)
                swap(t.s,t.e);
            edge[t.s].push_back(t);
            swap (t.s,t.e);
            edge[t.s].push_back(t);
        }
        for (int j=0;j<edge[sc].size();j++)
        {
            ready.insert(edge[sc][j]);

        }
        while(ready.size())
        {
            if (sc==ec)
            {
                cout<<arr[ec]<<endl;
                break;
            }

            t=*ready.begin();
            ready.erase(ready.begin());
            if(!arr[t.e])
            {
            arr[t.e]=t.cost;
              for (int j=0;j<edge[t.e].size();j++)
            {
                edge[t.e][j].cost+=arr[t.e];
                ready.insert(edge[t.e][j]);
            }

            }

             if (t.e==ec)
            {cout<<arr[t.e]<<endl;
                break;}
            if(!ready.size())
                cout<<"NONE"<<endl;
        }
        memset(arr,0,sizeof arr);
        c--;
    }
	system("pause");
    return 0;
}
