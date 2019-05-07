#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
char graph[5][5];
int conflict[16][16];
int n, ans;
int placed[16];

int can_place(int k)
{
    if(graph[k/n][k%n] == 'X')  return 0;
    for(int i=0;i<k;i++)
        if(placed[i] && conflict[k][i]) return 0;
    return 1;
}

void dfs(int k, int num)
{
    if(k == n*n)
    {
        if(num > ans)   ans = num;
        return;
    }
    if(!placed[k] && can_place(k))
    {
        placed[k] = 1;
        dfs(k+1, num+1);
        placed[k] = 0;
    }
    dfs(k+1, num);
}

int is_conflict(int a, int b)
{
    if(a == b)  return 1;
    int a_x = a/n, a_y = a%n, b_x = b/n, b_y = b%n;
    if(graph[a_x][a_y] == 'X' || graph[b_x][b_y] == 'X')
        return 0;
    if(a_x != b_x && a_y != b_y)    return 0;
    if(a_x == b_x)
    {
        if(a_y > b_y)
        {
            int c = a_y;
            a_y = b_y;
            b_y = c;
        }
        for(int i=a_y+1;i<b_y;i++)
            if(graph[a_x][i] == 'X')    return 0;
    }
    if(a_y == b_y)
    {
        if(a_x > b_x)
        {
            int c = a_x;
            a_x = b_x;
            b_x = c;
        }
        for(int i=a_x+1;i<b_x;i++)
            if(graph[i][a_y] == 'X')    return 0;
    }
    return 1;
}

int main()
{
    freopen("in.txt","r", stdin);
    while(scanf("%d",&n) && n!=0)
    {
        char ch;
        for(int i=0;i<n;i++)
        {
            ch = getchar();
            for(int j=0;j<n;j++)
                graph[i][j] = getchar();
        }
        for(int i=0;i<n*n;i++)
            for(int j=0;j<n*n;j++)
                conflict[i][j] = is_conflict(i, j);
        ans = 0;
        memset(placed, 0, sizeof(placed));
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}