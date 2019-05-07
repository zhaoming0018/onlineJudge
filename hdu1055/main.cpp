#include <stdio.h>
#include <string.h>
struct node
{
    int c, t, par;
    double sc;
}ns[1010];

int main()
{
    freopen("in.txt","r",stdin);
    int n,g;
    while(scanf("%d%d",&n,&g) && n!=0)
    {
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &ns[i].c);
            ns[i].t = 1, ns[i].sc = ns[i].c;
            sum += ns[i].c;
        }
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            ns[v].par = u;
        }
        for(int k=1;k<=n-1;k++)
        {
            double max = 0;
            int pos;
            for(int i=1;i<=n;i++)
            {
                if(i == g)  continue;
                if(ns[i].sc > max)
                    max = ns[i].sc, pos = i;
            }
            ns[pos].sc = 0;
            int p = ns[pos].par;
            sum += ns[p].t * ns[pos].c;
            ns[p].c += ns[pos].c;
            ns[p].t += ns[pos].t;
            ns[p].sc = ns[p].c*1.0/ns[p].t;
            for(int i=1;i<=n;i++)
                if(ns[i].par == pos)    ns[i].par = p;
        }
        printf("%d\n",sum);
    }
    return 0;
}