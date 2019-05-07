#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define N 100000
using namespace std;

struct point
{
    double x;
    double y;
}a[N];
int tmp[N];

bool compx(point &p, point &q)
{
    return p.x < q.x;
}

double dis(int i, int j)
{
    return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

bool compy(int p, int q)
{
    return a[p].y < a[q].y;
}

double closest(int left, int right)
{
    if(left == right)
        return 1000000;
    if(left+1 == right)
        return dis(left,right);
    int mid = (left+right)/2;
    double lmin = closest(left,mid);
    double rmin = closest(mid+1,right);
    double mmin = lmin < rmin ? lmin : rmin;
    int m = 0;
    tmp[m++] = mid;
    int t = mid-1;
    while(t>=left && fabs(a[t].x-a[mid].x)<mmin)
    {
        tmp[m++] = t;
        --t;
    }
    t = mid+1;
    while(t<=right && fabs(a[t].x-a[mid].x)<mmin)
    {
        tmp[m++] = t;
        ++t;
    }
    sort(tmp,tmp+m,compy);
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<i+4 && j<m;j++)
        {
            if(a[tmp[j]].y - a[tmp[i]].y >= mmin)
                break;
            double disij = dis(tmp[i], tmp[j]);
            if(disij < mmin)    mmin = disij;
        }
    }
    return mmin;
}

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf", &a[i].x, &a[i].y);
        sort(a,a+n,compx);
        printf("%.2lf\n", closest(0,n-1)/2);
    }
    return 0;
}
