#include <iostream>
#include<algorithm>
#include <cstring>


using namespace std;
int ncase,nr,dis;
int re[501],sum[501];
int main()
{
    cin>>ncase;
    for(int i =0;i<ncase;i++)
    {
        dis=0;
        cin>>nr;
        for (int k=0 ; k<nr;k++)
        {
            cin>>re[k];

        }

        for (int d=0;d<nr;d++)
            for(int k=0;k<nr;k++)
        {
            if (re[d]>=re[k])
                sum[d]+=re[d]-re[k];
            else
                sum[d]+=re[k]-re[d];
        }
        sort(sum,sum+nr);

        cout<<sum[0]<<endl;
        memset(sum,0,sizeof(sum));
    }
    return 0;
}
