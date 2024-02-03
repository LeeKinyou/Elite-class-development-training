#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[200000];
long long b[200000];
int main()
{
    ios::sync_with_stdio(0);
    int N;
    long long C;
    cin >> N >> C;
    int i,j;
    for (i=0;i<N;i++)
    {
        cin >> a[i];
        b[i]=a[i]-C;
    }
    sort(a, a + N - 1);
    long long sum=0;
    for (j=0;j<N;j++)
    {
        long long x=b[j];
        int l1=0,l2=0,r1=N-1,r2=N-1;
        int m1=(l1+r1)/2,m2=(l2+r2)/2;
        while (l1<=r1)
        {
            if (a[m1]>x)
            r1=m1-1;
            else
            l1=m1+1;
            m1=(l1+r1)/2; 
        }
        while (l2<=r2)
        {
            if (a[m2]>=x)
            r2=m2-1;
            else
            l2=m2+1;
            m2=(l2+r2)/2;
        }
        sum+=l1-l2;
    }
    cout << sum;
    return 0;
}