#include <iostream>
#include <stdio.h>
#define PI 3.1415927
using namespace std;

int main()
{
    double D,T;
    int r;
    int X = 0;
    while(scanf("%lf%d%lf",&D,&r,&T) && r!=0)
    {
        double dis = PI*D*r/12/5280;
        double mph = dis/T*3600;
        printf("Trip #%d: %.2lf %.2lf\n", ++X, dis, mph);
    }
    return 0;
}
