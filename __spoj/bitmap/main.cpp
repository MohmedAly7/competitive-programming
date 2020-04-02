#include <iostream>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
class node
{
    public:
    int i,j,cost=0;
};
queue<node> ready;
bool flag [182][182];
int c[182][182],n,m;
int in[5]={1,0,-1,0,1};
bool check (int i,int j)
{
    if (i>=n||j>=m||i==-1||j==-1)
        return 0;
    if (flag[i][j])
            return 0;
    return 1;
}
int main()
{
    int t;
    cin >>t;
    while (t)
    {
        cin>>n>>m;
        for (int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            scanf("%1d",&c[i][j]);
            if (c[i][j])
            {
                node tem;
                tem.i=i;
                tem.j=j;
                ready.push(tem);
                flag[tem.i][tem.j]=1;
                c[i][j]=0;
            }
        }
        while (ready.size())
        {
            node t=ready.front();
            ready.pop();
            c[t.i][t.j]=t.cost;
            for (int o=0;o<4;o++)
            {
                node te;
                if (check(t.i-in[o],t.j-in[o+1]))
                {
                    te.i=t.i-in[o];
                    te.j=t.j-in[o+1];
                    te.cost=t.cost +1;
                    flag[te.i][te.j]=1;
                    ready.push(te);
            }
            }

        }
        for (int i=0;i<n;i++)
           {for(int j=0;j<m;j++)
            cout<<c[i][j]<<" ";
            cout<<endl;
           }
           memset(flag,0,sizeof flag);
           memset(c,0,sizeof c);
        t--;
    }

    return 0;
}
