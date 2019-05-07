#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int x[5], y[5];
    double mindis=-1;
    for(int i=0;i<5;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int a=0;a<5;a++)
    for(int b=0;b<5;b++)
    for(int c=0;c<5;c++)
    for(int d=0;d<5;d++)
    for(int e=0;e<5;e++)
    {
        double dis=0;
        if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
        {
            dis += sqrt(x[a]*x[a]+y[a]*y[a]);
            dis += sqrt((x[b]-x[a])*(x[b]-x[a])+(y[b]-y[a])*(y[b]-y[a]));
            dis += sqrt((x[c]-x[b])*(x[c]-x[b])+(y[c]-y[b])*(y[c]-y[b]));
            dis += sqrt((x[d]-x[c])*(x[d]-x[c])+(y[d]-y[c])*(y[d]-y[c]));
            dis += sqrt((x[e]-x[d])*(x[e]-x[d])+(y[e]-y[d])*(y[e]-y[d]));
            dis += sqrt(x[e]*x[e]+y[e]*y[e]);
            if(mindis == -1)
                mindis = dis;
            else
                mindis = dis<mindis ? dis : mindis;
        }
    }
    printf("%lld\n", (long long)mindis);
    return 0;
}
