#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define INF 1e8
using namespace std;

int W, H, L, M, ans, sum;
int value[12];
int j_pos_x[12], j_pos_y[12];
int mark[12];
int start_x, start_y, end_x, end_y;
int map[50][50], visited[50][50], path[12][12];
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};

struct node
{
    int x,y,num;
    node(int tx, int ty, int tnum):
    x(tx), y(ty), num(tnum){}
};
queue<node> q;

void bfs(int x, int y, int k)
{
    memset(visited, 0, sizeof(visited));
    visited[x][y] = 1;
    while(!q.empty())   q.pop();
    q.push(node(x, y, 0));
    while(!q.empty())
    {
        node p = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node g = node(p.x+dx[i], p.y+dy[i], p.num+1);
            if(g.x>=0&&g.x< H&&g.y>=0&&g.y<W&&!visited[g.x][g.y]&&map[g.x][g.y]!='*')
            {
                visited[g.x][g.y] = 1;
                if(map[g.x][g.y]!='.')
                {
                    if(map[g.x][g.y] == '@')    path[k][0] = g.num;
                    else if(map[g.x][g.y] == '<')   path[k][M+1] = g.num;
                    else path[k][map[g.x][g.y]-'A'+1] = g.num;
                }
                q.push(g);
            }
        }
    }
}

void dfs(int pre, int time, int v)
{
    if(time > L || ans == sum)  return;
    if(pre == M+1)
    {
        if(v>ans)   ans = v;
        return;
    }
    for(int i=1;i<=M+1;i++)
    {
        if(mark[i]) continue;
        mark[i] = 1;
        dfs(i, time+path[pre][i], v+value[i]);
        mark[i] = 0;
    }
}

int main()
{
    int T;
    freopen("in.txt","r",stdin);
    scanf("%d", &T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d%d%d",&W,&H,&L,&M);
        for(int i=0;i<=M+1;i++)
        for(int j=0;j<=M+1;j++)
            path[i][j] = INF;
        sum = 0;
        // 错在这里，初始化
        memset(value, 0, sizeof(value));
        for(int i=1;i<=M;i++)
            scanf("%d", &value[i]), sum += value[i];
        for(int i=0;i<H;i++)
        {
            getchar();
            for(int j=0;j<W;j++)
            {
                map[i][j] = getchar();
                if(map[i][j]>='A' && map[i][j]<='J')
                    j_pos_x[map[i][j]-'A'+1] = i,
                    j_pos_y[map[i][j]-'A'+1] = j;
                else if(map[i][j] == '@')
                    j_pos_x[0] = i, j_pos_y[0] = j;
                else if(map[i][j] == '<')
                    j_pos_x[M+1] = i, j_pos_y[M+1] = j;
            }
        }
        for(int i=0;i<=M+1;i++)
            bfs(j_pos_x[i], j_pos_y[i], i);
        ans = -1;
        memset(mark, 0, sizeof(mark));
        dfs(0,0,0);
        printf("Case %d:\n", kase);
        if(ans==-1) 
            printf("Impossible\n");
        else
            printf("The best score is %d.\n",ans);
        if(kase != T)
            printf("\n");
    }
    return 0;
}