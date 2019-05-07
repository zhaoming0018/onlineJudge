#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define N 110
using namespace std;
int bug[N], brain[N];
int dp[N][N];
vector<int> edge[N];
int visited[N];
int m,n;

int max(int x,int y)
{
    return x>y?x:y;
}

void dfs(int p)
{
    int temp = (bug[p]+19)/20;
    for(int i=temp;i<=m;i++)
        dp[p][i] = brain[p];
    visited[p] = 1;
    for(unsigned int i=0;i<edge[p].size();i++)
    {
        int t = edge[p][i];
        if(visited[t])  continue;
        dfs(t);
        for(int j=m;j>=temp;j--)
        {
            // 要求至少保留temp人，保证经过了洞穴p
            for(int k=1;k<=j-temp;k++)
                dp[p][j] = max(dp[p][j], dp[p][j-k]+dp[t][k]);
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) && n!=-1)
    {
        for(int i=0;i<=n;i++)   edge[i].clear();
        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));
        for(int i=1;i<=n;i++)
            scanf("%d%d", &bug[i], &brain[i]);
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        if(m == 0)
        {
            printf("0\n");
        }else
        {
            dfs(1);
            printf("%d\n", dp[1][m]);
        }
    }
    return 0;
}
