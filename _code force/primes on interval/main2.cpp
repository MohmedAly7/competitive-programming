#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool prime[1000001]={true};
int nprime[1000001][2];
int a,b,k,l=1000000,mid,ans=10000000,p=1,v;
bool check (int mn)
{
    for(int i=1;i<p;i++)
    {
        if(nprime[i][0]<a)
            continue;
            bool w=0;
        int con =0,cnt=0;
        while (mn>=con)
        {
            int h=i;
            con+=nprime[h+1][1];
            cnt++;
            h++;
             if(nprime[h+1][0]>b)
            break;
        }
        l=min(l,cnt);
        cout<<l <<endl;
        if(nprime[i+1][0]>b)
            break;

    }
    if(l>=k)
        return 1;
    return 0;

}
int solve (int a,int b)
{
    if (a>b) return mid;
    mid =(a+b)/2;
    cout<<mid<<" ";
    if (check(mid)){
            ans=min(mid,ans);
        return solve (a,mid-1);}
    else return solve (mid+1,b);


}
int main()
{
    memset(prime,1,sizeof prime);
    prime[0]=0,prime[1]=0;
    for (int i=2;i<1000000;i++)
 {
       if (prime[i])
    {
        nprime[p][1]=i-nprime[p-1][0];
        nprime[p++][0]=i;

        for(int j=i+i;j<1000000;j=j+i)
            prime[j]=0;
    }

 }
 for (int i=0;i<100;i++)
 cout<<nprime[i][0]<<" "<<nprime[i][1]<<endl;
    cin>>a>>b>>k;
    solve(1,b);
    cout<<ans;
    return 0;
}
