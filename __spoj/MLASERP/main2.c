#include <iostream>
#include <set>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>

using namespace std;
int cnt=0,h,w,coun;
char k;
bool flag [101][101];
pair<int,int> se[2];
int in [6]={1,0,-1,0,1,0};
int r[4]={1,2,3,4};
class p
{
public:
    char c;
    int i,l,rood,cost=0;
    bool ava=0;

 void ch()
    {
        if (c=='.'||c=='C')
            ava=1;
    }
};
p arr [101][102];
set<p> ready;
bool operator < (p a,p b)
{
    if (a.cost != b.cost) return (a.cost <b.cost);

  return abs(se[0].first - a.i)+abs(se[0].second-a.l)<=abs(se[0].first - b.i)+abs(se[0].second -b.l);
}
bool check (int i , int j)
{
    if (i>=h||j>=w||i==-1||j==-1) return 0;
    if (flag[i][j])
        return 0;
    return arr[i][j].ava;
}
void (p t)
{
    for (int o=0;o<4;o++)
   {
       p tem =arr[t.i-in[o]][t.l-in[o+1]];
       tem.cost=t.cost;
       tem.rood=r[o];
       if (tem.rood==t.rood)
        ready.insert(tem);
       else if (abs(tem.rood-t.rood)==1||abs(tem.rood-t.rood)==3)
       {
           tem.cost+=1;
            ready.insert(tem);
       }
   }
}

int main()
{
    cin >>w>>h;

    for (int x =0;x<h;x++)
      {for (int y=0;y<w;y++)
    {
        cin>>k;
        p t;
        t.i=x;
        t.l=y;
        t.c=k;
        t.ch();
        arr[x][y]=t;
        if (k=='C')
        {
            se[cnt].first=x;
            se[cnt++].second=y;
        }
    }

}
 flag[se[0].first][se[0].second]=1;
      for (int o=0;o<4;o++)
      {

           cout<<check(se[0].first-in[o],se[0].second-in[o+1])<<"   +"<<se[0].first-in[o]<<"    "<<se[0].second-in[o+1]<<endl;
           if(check(se[0].first-in[o],se[0].second-in[o+1]))
       {
           arr[se[0].first-in[o]][se[0].second-in[o+1]].rood=r[o];
           ready.insert(arr[se[0].first-in[o]][se[0].second-in[o+1]]) ;
            coun++;
           cout <<"done"<<endl;
       }
      }
    while(ready.size())
    {
        p te=*ready.beagin();
    }




 return 0;
}
