#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        double sum = 0;
        for(int i=1;i<=x;i++)
            sum += log10(i);
        printf("%d\n", (int)sum+1);
    }
    return 0;
}
