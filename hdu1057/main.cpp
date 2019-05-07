#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
int n;
int dna[20];
int a[2][25][25];
using namespace std;

char sign(int x)
{
    char st[]=".!X#";
    return st[x];
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    memset(a,0,sizeof(a));
    for(int t=0;t<T;t++)
    {
        scanf("%d",&n);
        for(int i=0;i<16;i++)
        {
            scanf("%d",&dna[i]);
        }
        for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++)
        {
            scanf("%d", &a[0][i][j]);
        }
        for(int k=0;k<n;k++)
        {
            int from = k%2, to = (k+1)%2;
            for(int i=1;i<=20;i++)
            for(int j=1;j<=20;j++)
            {
                int f = a[from][i][j]+a[from][i-1][j]+a[from][i+1][j]+a[from][i][j-1]+a[from][i][j+1];
                a[to][i][j] = a[from][i][j]+dna[f];
                if(a[to][i][j]>3)   a[to][i][j] = 3;
                if(a[to][i][j]<0)   a[to][i][j] = 0;
            }
        }
        for(int i=1;i<=20;i++)
        {
            int d = n%2;
            for(int j=1;j<=20;j++)
                putchar(sign(a[d][i][j]));
            putchar('\n');
        }
        if(t!=T-1)  putchar('\n');
    }
    return 0;
}