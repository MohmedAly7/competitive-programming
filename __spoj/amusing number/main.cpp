#include <iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
unsigned long long k,n;string num ;
unsigned long long i;long di;
int main()

{
    cin >>n;
    while(n )
        {
    cin>> k;
    di=0;
    for ( i=2;i<k;i=i*2)
    {
        k=k-i;
        di++;
    }
    i=i/2;
    for (;di>=0;di--)
    {
        if (i>=k)
        {
            num+='5';
            i=i/2;
         }
        else
        {   num+='6';
            k=k-i;
            i=i/2;
        }
    }
    cout <<num<<endl;
   num.clear();

    n--;
    }
       return 0;
}
