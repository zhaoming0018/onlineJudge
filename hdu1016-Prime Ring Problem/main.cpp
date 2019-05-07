#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int cycle[20];
int ha[40], prime[40];
int n;

void dfs(int k)
{
    if(k == n)
    {
        if(prime[cycle[n-1]+1])
        {
            for(int i=0;i<n;i++)
            {
                if(i == 0)
                    printf("%d",cycle[0]);
                else
                    printf(" %d",cycle[i]);
            }
            printf("\n");
        }
    }else{
        for(int i=2;i<=n;i++)
        {
            if(!ha[i] && prime[cycle[k-1]+i])
            {
                ha[i] = 1;
                cycle[k] = i;
                dfs(k+1);
                ha[i] = 0;
            }
        }
    }
}

int main()
{
    int T = 0;
    memset(prime,0,sizeof(prime));
    prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=prime[37]=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(cycle, 0, sizeof(cycle));
        memset(ha, 0, sizeof(ha));
        cycle[0] = 1;
        ha[1] = 1;
        printf("Case %d:\n",++T);
        dfs(1);
        printf("\n");

    }
    return 0;
}
