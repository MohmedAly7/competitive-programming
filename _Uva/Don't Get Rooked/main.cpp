#include <iostream>
#include<stdio.h>
using namespace std;
char grid [4][4];
int n =1;
int mx,res,mres,cur;
bool save1(int x, int y)
 {

    if (grid [x][y]=='X')return 1 ;
    if (x>n)return 1 ;
     if (grid [x][y]=='R')return 0;
    return save1(x+1,y);

 }
 bool save2(int x, int y)
 {
    if (grid [x][y]=='X')return 1 ;
    if (y>n)return 1 ;
    if (grid [x][y]=='R')return 0;

    return save2(x,y+1);

 }bool save3(int x, int y)
 {

    if (grid [x][y]=='X')return 1 ;
    if (x<0)return 1 ;
     if (grid [x][y]=='R')return 0;
    return save3(x-1,y);

 }
 bool save4(int x, int y)
 {
    if (grid [x][y]=='X')return 1 ;
    if (y<0)return 1 ;
    if (grid [x][y]=='R')return 0;

    return save4(x,y-1);

 }
    int solve (int x,int y,int cnt)
    {

        if (x==n)
             return (cnt) ;
        if (y==n)
            {   y=0;
                solve (x+1,y,cnt);
                return cnt;
            }

        if (grid[x][y]=='.'&&save1(x,y)&&save2(x,y)&&save3(x,y)&&save4(x,y)){
        grid[x][y]='R';
        mx=solve (x,y+1,cnt+1);
        grid[x][y]='.';
        }

        if (mres<mx)
            mres=mx;

            solve (x,y+1,cnt);

        return cnt;

    }
int main()
{
    cin>>n;
    while (n!=0)
   {

    mres=0,mx=0;
    for (int i=0;i<n;i++)
        for (int k=0;k<n;k++)
            cin>>grid[i][k];


        solve (0,0,0);
        cout<<mres<<endl;
        cin>>n;

   }



    return 0;
}
