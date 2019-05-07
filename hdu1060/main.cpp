#include <stdio.h>
#include <math.h>
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        double tmp;
        printf("%d\n",(int)(pow(10, modf(log10(n)*n, &tmp))));
    }
    return 0;
}