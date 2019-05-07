#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

struct node
{
    int x,y;
};
node start , finish;

int n,m,t, flag = 0;
char maze[7][7];
int visited[7][7];

void dfs(node p, int step)
{
    if(step == t && maze[p.x][p.y] == 'D')  flag = 1;
    if(flag)    return;
    if(step == t)   return;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for(int i=0;i<4;i++)
    {
        node tmp;
        tmp.x = p.x + dx[i], tmp.y = p.y + dy[i];
        if(tmp.x >= 0 && tmp.x < n && tmp.y >= 0 && tmp.y < m && maze[tmp.x][tmp.y]!='X' && visited[tmp.x][tmp.y] == 0)
        {
            // 起始位置标记为已访问
            visited[tmp.x][tmp.y] = 1;
            dfs(tmp, step+1);
            if(flag) return;
            visited[tmp.x][tmp.y] = 0;
        }
    }
    return;
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&t) && n!=0)
    {
        flag = 0;
        getchar();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
                    maze[i][j] = getchar();
                    if(maze[i][j] == '.')
                        ++cnt;
                    if(maze[i][j] == 'S')
                        start.x = i, start.y = j;
                    if(maze[i][j] == 'D')
                        finish.x = i, finish.y = j;
                }
                getchar();
        }
        if((start.x+finish.x+start.y+finish.y-t)%2 == 0 && t <= cnt + 1)
        {
            memset(visited,0,sizeof(visited));
            visited[start.x][start.y] = 1;
            dfs(start, 0);
        }

        if(flag) printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}
