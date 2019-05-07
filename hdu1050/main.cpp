#include <stdio.h>
#include <string.h>
int main()
{
    freopen("in.txt","r",stdin);
    int T, a[5000], maxn;
    scanf("%d",&T);
    while(T--)
    {
        maxn = 0;
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x = (x+1)/2;
            y = (y+1)/2;
            if(x>y)
            {
                int c = x; x =y; y=c;
            }
            for(int i=x;i<=y;i++)
            {
                a[i]++;
                if(a[i]>maxn)   maxn = a[i];
            }
        }
        printf("%d\n",maxn*10);
    }
    return 0;
}