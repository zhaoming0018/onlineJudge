#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct node
{
    int x, y;
}g[5010];
int dp[5010];

int cmp(node n1, node n2)
{
    return n1.x < n2.x;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d", &g[i].x, &g[i].y);
        sort(g, g+n, cmp);
        memset(dp, 0, sizeof(dp));
        int ans = 1;
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            int tmp = 0;
            for(int j=0;j<i;j++)
            {
                if(g[j].x == g[i].x)    continue;
                if(g[j].y > g[i].y) tmp = dp[j]>tmp?dp[j]:tmp;
            }
            dp[i] = tmp+1;
            if(dp[i]>ans)   ans = dp[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}