#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        printf("Scenario #%d:\n", i);
        if((x*y) & 1)   printf("%.2lf\n\n", (double)x*y-1+sqrt(2));
        else    printf("%.2lf\n\n", (double)x*y);
    }
    return 0;
}