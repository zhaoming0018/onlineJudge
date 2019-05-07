#include <stdio.h>
#include <math.h>
int main()
{
    int n,u,d;
    while(scanf("%d%d%d",&n,&u,&d) && n!=0)
    {
        int ans = ceil((n-u)*1.0/(u-d))*2+1;
        printf("%d\n",ans);
    }
    return 0;
}