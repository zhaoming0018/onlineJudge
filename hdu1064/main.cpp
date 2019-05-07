#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    double x, sum;
    while(scanf("%lf",&x)!=EOF)
    {
        sum = x;
        for(int i=0;i<11;i++)
        {
            scanf("%lf",&x);
            sum += x;
        }
        printf("$%.2lf\n",sum/12);
    }
    return 0;
}