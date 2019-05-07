#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int dx[4] = {-1,1,0,0}, dy[4]={0,0,1,-1};

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) && n!=0)
    {
        int col;
        int a[15][15], visited[15][15];
        memset(visited,0,sizeof(visited));
        scanf("%d", &col);
        for(int i=1;i<=n;i++)
        {
            char ch = getchar();
            for(int j=1;j<=m;j++)
            {
                ch = getchar();
                switch(ch){
                case 'N':
                    a[i][j] = 0;
                    break;
                case 'S':
                    a[i][j] = 1;
                    break;
                case 'E':
                    a[i][j] = 2;
                    break;
                case 'W':
                    a[i][j] = 3;
                    break;
                }

            }
        }
        int cx[200], cy[200], t=1;
        cx[1] = 1, cy[1] = col;
        visited[1][col] = 1;
        while(true)
        {
            int dir = a[cx[t]][cy[t]];
            cx[t+1] = cx[t]+dx[dir];
            cy[t+1] = cy[t]+dy[dir];
            t = t+1;
            if(cx[t] == 0 || cy[t] == 0 || cx[t]>n || cy[t]>m)
            {
                printf("%d step(s) to exit\n",t-1);
                break;
            }else if(visited[cx[t]][cy[t]])
            {
                printf("%d step(s) before a loop of %d step(s)\n",visited[cx[t]][cy[t]]-1, t-visited[cx[t]][cy[t]]);
                break;
            }else{
                visited[cx[t]][cy[t]] = t;
            }
        }
    }
    return 0;
}
