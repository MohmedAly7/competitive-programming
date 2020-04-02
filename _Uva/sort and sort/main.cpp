#include <iostream>
#include<algorithm>

using namespace std;
int nm[10001];
int n,mod;
bool cmp(int b,int a)
{
    if (b%mod<a%mod)
        return 1;
    if (b%mod==a%mod&&b%2!=0&&a%2==0)
        return 1;
    if (b%mod==a%mod&&b%2!=0&&a%2!=0&&b>a)
        return 1;
    if (b%mod==a%mod&&b%2==0&&a%2==0&&b<a)
        return 1;

    return 0;
}

int main()
{
   while(1){
    cin>>n>>mod;
    if (n==0&&mod==0){
        cout<<n<<" "<<mod<<endl;
        break;
        }
    for (int i=0;i<n;i++)
        cin>>nm[i];

    sort(nm,nm+n,cmp);
    cout<<n<<" "<<mod<<endl;
    for (int i=0;i<n;i++)
        cout<<nm[i]<<endl;
    }

    return 0;
}
