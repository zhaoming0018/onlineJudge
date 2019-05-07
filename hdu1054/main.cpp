#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int n;
vector<int> a[1510];
int mark[1510], match[1510], used[1510];

int dfs(int k)
{
    for(int j=0;j<a[k].size();j++)
    {
        int i = a[k][j];
        if(!used[i])
        {
            used[i] = 1;
            if(mark[i] == -1 || dfs(mark[i]))
            {
                mark[i] = k;
                mark[k] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)    a[i].clear();
        for(int i=0;i<n;i++)
        {
            int u,t;
            scanf("%d",&u);
            scanf(":(%d)",&t);
            for(int j=0;j<t;j++)
            {
                int v;
                scanf("%d", &v);
                a[u].push_back(v);
                a[v].push_back(u);
            }
        }
        int ans = 0;
        memset(mark,-1,sizeof(mark));
        for(int i=0;i<n;i++)
        if(mark[i] == -1)
        {
            memset(used, 0, sizeof(used));
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}