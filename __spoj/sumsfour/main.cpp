#include <iostream>
#include<algorithm>

using namespace std;
int a[4000],b[4000],c[4000],d[4000],ab[4000*4000],cd[4000*4000],n,k,l,cnt,top;
bool solve (int st ,int en)
{
    int mid = (st+en)/2;
    if (cd[mid] ==top)return true;
    if (st>=en) return false;
    if (cd[mid] < top )return solve (mid+1,en);
    if (cd[mid] >top) return solve (st,mid-1);
}
int main()
{
    cin >>n;
    for (int i =0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for (int i =0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            ab[k++]=a[i]+b[j];
            cd[l++]=c[i]+d[j];
        }
        sort(cd,cd+n*n);
        for (int i=0;i<n*n;i++)
        {
             top=ab[i]*-1;
           if (solve (0,n*n))
            {
                cnt+=upper_bound(cd,cd+n*n,top)-lower_bound(cd,cd+n*n,top);
            }
        }
        cout <<cnt;



    return 0;
}
