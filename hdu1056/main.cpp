#include <stdio.h>

int main()
{
    double x;
    while(scanf("%lf",&x) && x!=0 )
    {
        int i = 2;
        double sum = 0;
        while(sum < x)
        {
            sum += 1.0/i;
            i = i+1;
        }
        printf("%d card(s)\n", i-2);
    }
    return 0;
}