/*
ID: m.a.lea1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include<stdio.h>

using namespace std;
FILE * in = fopen("milk2.in","r");
FILE * out = fopen("milk2.out","w");

bool tim[1000001];
int st,en,maxen,wt,rt,mwt,mrt,N,lst=1000000;
int main()
{
   // cin>>N;
    fscanf(in,"%d",&N);
    for (int i =0 ; i<N; i++)
    {
        fscanf(in,"%d %d",&st,&en);
        if (st<lst)
            lst =st;
        if (maxen<en)
            maxen=en;
        for (;st<en;st++)
            tim[st]=1;
    }
    for (int i=lst;i<maxen;i++)
        {
            if (tim[i])
                wt++,rt=0;
            else
                rt++,wt=0;
            if (mwt<wt)
                mwt=wt;
            if (mrt<rt)
                mrt=rt;
        }
     //  cout <<mwt<<endl <<mrt;
     fprintf(out,"%d %d",mwt,mrt);
     fprintf(out,"\n");

    return 0;
}
