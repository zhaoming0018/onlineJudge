#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
int a[10];
int d[120001];
int sum = 0;

void CompletePack(int c)
{
    for(int i=c;i<=sum;i++)
        d[i] |= d[i-c];
}

void ZeroOnePack(int c)
{
    for(int i=sum;i>=c;i--)
        d[i] |= d[i-c];
}

void dp(int c, int t)
{
    if(t*c >= sum)   {CompletePack(c); return;}
    int k=1;
    while(k<t)
    {
        ZeroOnePack(c*k);
        t -= k;
        k <<= 1;
    }
    ZeroOnePack(c*t);
}

int main()
{
    freopen("in.txt","r",stdin);
    int t = 0;
    while(true)
    {
        sum = 0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&a[i]);
            sum += i*a[i];
        }
        if(sum == 0)    break;
        printf("Collection #%d:\n",++t);
        if(sum & 1)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(d,0,sizeof(d));
        sum = sum/2;
        d[0] = 1;
        for(int i=1;i<=6;i++)
            dp(i,a[i]);
        if(d[sum] == 1)
        {
            printf("Can be divided.\n\n");
        }else{
            printf("Can't be divided.\n\n");
        }
    }
    return 0;
}