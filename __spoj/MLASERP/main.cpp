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
  return 1;
  ///return abs(se[0].first - a.i)+abs(se[0].second-a.l)<abs(se[0].first - b.i)+abs(se[0].second -b.l);
}
bool check (int i , int j)
{
    if (i>=h||j>=w||i==-1||j==-1) return 0;
    if (flag[i][j])
        return 0;
    return arr[i][j].ava;
}
void ins (int i ,int j)
{
   for (int o=0;o<4;o++)
   {
       int cos=arr[i][j].cost;
      if(check(i-in[o],j-in[o+1]))
       {
           arr[i-in[o]][j-in[o+1]].rood=r[o];
           arr[i-in[o]][j-in[o+1]].cost=cos;
           cout<<arr[i-in[o]][j-in[o+1]].rood<<" /";
           if (arr[i-in[o]][j-in[o+1]].rood==arr[i][j].rood)
           {
               ready.insert(arr[i-in[o]][j-in[o+1]]);coun++;
           }
          else  if ((arr[i-in[o]][j-in[o+1]].rood-arr[i][j].rood)==1||(arr[i-in[o]][j-in[o+1]].rood-arr[i][j].rood)==-1||(arr[i-in[o]][j-in[o+1]].rood-arr[i][j].rood)==3||(arr[i-in[o]][j-in[o+1]].rood-arr[i][j].rood)==-3){
           arr[i-in[o]][j-in[o+1]].cost+=1;
           ready.insert(arr[i-in[o]][j-in[o+1]]);coun++;
          } cout<<arr[i-in[o]][j-in[o+1]].cost<<endl;

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
     } for (int x =0;x<h;x++)
      {for (int y=0;y<w;y++)
      cout<<arr[x][y].ava<<"   ";
      cout<<endl;
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
    while (ready.size())
    {
        p tem=*ready.begin();
        cout<<coun<<" ++"<<endl;
        ready.erase(ready.begin());
        coun--;

        if (flag[tem.i][tem.l]==0)
        {
            cout<<tem.i<<tem.l<<"***"<<endl;
            ins(tem.i,tem.l);
            flag[tem.i][tem.l]=1;
        }
        cout<<coun<<" +"<<ready.size()<<endl;
    }
    cout<<arr[se[1].first][se[1].second].cost<<endl;


    return 0;
}
