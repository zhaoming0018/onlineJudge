#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXN 500010
using namespace std;
int road[MAXN], B[MAXN];

void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}

int main()
{
    int n,x,y,i;
    int T = 0, len;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            read(x), read(y);
            road[x] = y;
        }
        B[1] = road[1];
        len = 1;
        for(i=2;i<=n;i++)
        {
            if(road[i]>B[len])
                B[++len] = road[i];
            else
            {
                int pos = lower_bound(B+1,B+len+1,road[i])-B;
                B[pos] = road[i];
                if(pos > len)   ++len;
            }
        }
        printf("Case %d:\n", ++T);
        if(len == 1)
            printf("My king, at most 1 road can be built.\n\n");
        else
            printf("My king, at most %d roads can be built.\n\n", len);
    }
    return 0;
}
