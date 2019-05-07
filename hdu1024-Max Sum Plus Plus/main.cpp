#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAXN 1000100
#define INF 0x7fffffff
int a[MAXN];
int dp[MAXN], pre[MAXN];
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int m,n,i,j,maxx;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(i=1;i<=n;i++)    scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
        {
            maxx = -INF;
            for(j=i;j<=n;j++)
            {
                dp[j] = max(dp[j-1], pre[j-1])+a[j];
                pre[j-1] = maxx;
                maxx = max(maxx, dp[j]);
            }
        }
        printf("%d\n", maxx);
    }
    return 0;
}
