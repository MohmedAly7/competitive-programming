#include <iostream>
#include<stdio.h>
#include<ctype.h>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;



char str[20001];
char first [20001];
int index [20001];
int main()
{
    scanf("%[^\n]",first);
    int k=0;
    for (int i = 0 ; first[i] ;i++ )
        if ( isalpha(first[i]) )
            {
                str[k++]= tolower(first [i]);
                index[k++]=i;
            }

    int maxi=0,s=0,e=0,s1=0,e1=0;
    for (int i=0; str[i] ;i++ )
        {
            int a=i, b=i+1,N=0;
            while  (a>=0 && b<k && str[a]==str[b] )
                 a--,N=N+2,b++;
            if(N>maxi)
                maxi = N, s = a+1, e = b-1;
            a=i-1, b=i+1,N=1;
            while  (a>=0 && b<k && str[a]==str[b] )
                 a--,N=N+2,b++;
            if(N>maxi)
                maxi = N, s = a+1, e = b-1;

        }

        cout <<s<<endl << e<<endl;
    while (s1>e1)
    {
        cout << first [s1];
        s++;
    }
    cout<<maxi<<endl;
    return 0;
}
