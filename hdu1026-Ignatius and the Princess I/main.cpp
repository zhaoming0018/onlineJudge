#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
const int INF = 1e8;

struct point{
    int x;
    int y;
};

struct ele{
    point cur;
    int sum;
    point from;
    friend bool operator < (ele a, ele b)
    {
        return a.sum > b.sum;
    }
}area[100][100];
int dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1};
int graph[100][100];

void print(point p)
{
    if(p.x == 0 && p.y == 0)  return;
    point fr = area[p.x][p.y].from;
    print(fr);
    printf("%ds:(%d,%d)->(%d,%d)\n",area[fr.x][fr.y].sum+1,fr.x, fr.y, p.x,p.y);
    for(int i=0;i<graph[p.x][p.y];i++)
    {
        printf("%ds:FIGHT AT (%d,%d)\n", area[fr.x][fr.y].sum+1+i+1,p.x,p.y);
    }
}

int main()
{
    int n,m;

    priority_queue<ele> q;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            getchar();
            for(int j=0;j<m;j++)
            {
                char ch = getchar();
                if(ch == 'X')   graph[i][j] = -1;
                else if(ch == '.')  graph[i][j] = 0;
                else graph[i][j] = ch-'0';
                area[i][j].sum = INF;
                area[i][j].cur.x = i, area[i][j].cur.y = j;
            }
        }
        if(graph[0][0] == -1)
        {
            printf("God please help our poor hero.\nFINISH\n");
            continue;
        }
        while(!q.empty())   q.pop();
        point sign0;
        sign0.x = -1, sign0.y = -1;
        area[0][0].from = sign0, area[0][0].sum = 0;
        q.push(area[0][0]);
        bool flag = false;
        while(!q.empty())
        {
            ele temp = q.top();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x = temp.cur.x+dx[i], y = temp.cur.y+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && graph[x][y]>=0 && temp.sum+graph[x][y]+1<area[x][y].sum)
                {
                    // ¸üÐÂarea
                    area[x][y].from = temp.cur;
                    area[x][y].sum = temp.sum+graph[x][y]+1;
                    if(x == n-1 && y == m-1)
                    {
                        flag = true;
                        break;
                    }
                    q.push(area[x][y]);
                }
            }
            if(flag)    break;
        }
        if(flag)
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",area[n-1][m-1].sum);
            print(area[n-1][m-1].cur);
            printf("FINISH\n");
        }else{
            printf("God please help our poor hero.\nFINISH\n");
        }
    }
    return 0;
}
