#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
double a[100010];


struct num_label
{
    double num;
    int label;
    num_label(double x, int y):
        num(x), label(y){}
    friend bool operator < (num_label a, num_label b)
    {
        if(a.num != b.num)  return a.num < b.num;
        else    return a.label > b.label;
    }
};

int main()
{
    int m,n,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            double x;
            for(int j=0;j<m;j++)
                scanf("%lf", &x), a[j]+=x;
        }
        priority_queue<num_label> pq;
        priority_queue<int> pi;
        while(!pq.empty())  pq.pop();
        while(!pi.empty())  pi.pop();
        for(int i=0;i<m;i++)
            pq.push(num_label(a[i], i+1));
        for(int i=0;i<k;i++)
        {
            num_label t = pq.top();
            pq.pop();
            pi.push(t.label);
        }
        for(int i=0;i<k;i++)
        {
            int u = pi.top();
            pi.pop();
            if(i==k-1)  printf("%d\n", u);
            else    printf("%d ", u);
        }
    }
    return 0;
}
