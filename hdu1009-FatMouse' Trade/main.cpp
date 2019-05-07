#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct trade{
    int j;
    int f;
}a[1000];

bool cmp(const trade &x, const trade &y)
{
    return x.j*y.f > y.j*x.f;
}

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n) && n!=-1)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].j, &a[i].f);
        sort(a,a+n,cmp);
        int i = 0;
        double total = 0;
        while(m!=0 && i<n)
        {
            if(a[i].f < m)
                total += a[i].j, m = m - a[i].f;
            else
                total += m*a[i].j*1.0/a[i].f, m = 0;
            ++i;
        }
        printf("%.3lf\n",total);
    }
    return 0;
}
