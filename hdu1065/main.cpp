#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
// 这个数值，换了其它的会出错
const double PI=3.1415926;
using namespace std;

int main()
{
    int n;
    double x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&x,&y);
        printf("Property %d: This property will begin eroding in year %d.\n",i, (int)(PI*(x*x+y*y)/100.0)+1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}