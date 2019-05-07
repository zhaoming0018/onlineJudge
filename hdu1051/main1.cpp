#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
struct node{
    int x,y;
}g[5010];
int n;
vector<int> v[5010];
int used[5010], mark[5050];

int find(int k)
{
    int t_size = v[k].size();
    for(int j=0;j<t_size;j++)
    {
        int i = v[k][j];
        if(!used[i])
        {
            used[i] = 1;
            if(mark[i] == 0 || find(mark[i]))
            {
                mark[i] = k;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   v[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&g[i].x, &g[i].y);
            for(int j=1;j<i;j++)
            {
                if(g[i].x < g[j].x && g[i].y < g[j].y)  v[i].push_back(j);
                if(g[j].x < g[i].x && g[j].y < g[i].y)  v[j].push_back(i);
                if(g[i].x == g[j].x && g[i].y == g[j].y)    v[i].push_back(j);
            }
        }
        int ans = 0;
        memset(mark, 0, sizeof(mark));
        for(int i=1;i<=n;i++)
        {
            memset(used, 0, sizeof(used));
            if(find(i)) ans++;
        }
        printf("%d\n", n-ans);
    }
    return 0;
}