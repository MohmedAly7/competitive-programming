#include <iostream>

using namespace std;
int num [9][4]={{1},{2,4,8,6},{3,9,7,1},{4,6},{5},{6},{7,9,3,1},{8,4,2,6},{9,1}};
int mod [9]={1,4,4,2,1,1,4,4,2};
long N,T,pow;
int main()
{cin>>T;
    while(T)
    {cin>>N>>pow;
        T--;
        if (N==0)
        {cout<<N<<endl;continue;}
        if (pow==0)
        {cout<<1<<endl;continue;}
        if (N>=10)N=N%10;
        if (N==0)
        {cout<<N<<endl;continue;}
        pow=pow%mod[N-1];
        if (pow==0)
        pow=mod[N-1];
        cout <<num[N-1][pow-1]<<endl;}
    return 0;
    }
