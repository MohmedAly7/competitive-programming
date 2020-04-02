#include <iostream>
#include<stdio.h>

using namespace std;

bool tim[1000001];
int st,en,maxen,wt,rt,mwt,mrt,N,lst=1000000;
int main()
{
    cin>>N;

    for (int i =0 ; i<N; i++)
    {
        cin>>st>>en;
        if (st<lst)
            lst =st;
        if (maxen<en)
            maxen=en-1;
        for (;st<=en-1;st++)
            tim[st-1]=1;
    }
    for (int i=lst;i<=maxen;i++)
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
        cout <<mwt<<endl <<mrt;

    return 0;
}
