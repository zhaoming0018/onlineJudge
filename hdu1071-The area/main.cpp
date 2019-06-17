#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        double x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double a = (y2-y1)/(x2-x1)/(x2-x1);
        double k = (y3-y2)/(x3-x2);
        double b = y2-k*x2;
        double three = a/3*(pow(x3-x1,3) - pow(x2-x1,3));
        double two = -0.5*k*(x3*x3-x2*x2);
        double one = (y1-b)*(x3-x2);
        double res = three+two+one;
        if(res<0)   res = -1*res;
        printf("%.2lf\n",res);
    }
    return 0;
}