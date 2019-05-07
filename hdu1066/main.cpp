#include <stdio.h>
#include <string.h>
#define MAXN 10000
const int R[] = {1,1,2,6,4,2,2,4,2,8};
const int G[] = {6,6,2,6,4,4,4,8,4,6};
const int C[] = {2,6,8,4}; 
int a[MAXN];

int H(int X, int Y)
{
    int i;
    for(i = 0;i<4;i++)
        if(C[i] == X)   break;
    return C[(i+Y)%4];
}

int F(char* st)
{
    int len = strlen(st);
    if(len == 1)    return R[st[0]-'0'];
    for(int i=0;i<len;i++)
        a[i] = st[len-1-i]-'0';
    int res = 1;
    while(len>1)
    {
        int k = a[0], g = 2*a[0]/10;
        a[len] = 0;
        for(int i=1;i<len;i++)
        {
            int s = a[i]*2+g;
            g = s/10;
            a[i-1] = s%10;
        }
        a[len-1] = g;
        if(g == 0)  len--;
        // 仅后两位会影响除以2的次数，第三位*100已经是4的倍数了
        res = res* H(G[k], a[0]+10*a[1]) %10;
    }
    res = res*R[a[0]]%10;
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    char st[MAXN];
    while(scanf("%s", st)!=EOF)
        printf("%d\n", F(st));
    return 0;
}