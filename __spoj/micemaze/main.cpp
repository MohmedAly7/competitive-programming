#include <iostream>
#include<cstring>
using namespace std;
int room,edge,End,tim,cnt;
int rood[101][101];
bool flag[101][101];
int x,y,t;
int main()
{
    memset(flag,0,sizeof flag);
    memset(rood,99,sizeof rood);

    cin>>room>>End>>tim>>edge;
    for (int i =0;i<edge;i++)
    {
        cin>>x>>y>>t;
        rood[x][y]=t;
        flag[x][y]=1;
    }
    for (int k=1;k<=room;k++)
        for (int i=1;i<=room;i++)
            for (int j=1;j<=room;j++)
            {
                if (flag[i][k]&&flag[k][j])
                {
                    flag[i][j] = 1;
                    rood[i][j]=min(rood[i][j],rood[i][k]+rood[k][j]);
                }

            }
        rood[End][End]=0;
        for (int i=1;i<=room;i++)
            if (rood[i][End]<=tim)
              {
                 cnt++;
              }
            cout <<cnt;

    return 0;
}
