#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int x,int y)
{
    int c;
    if(x<y)
        c=x,x=y,y=c;
    c = x%y;
    while(c!=0)
        x = y, y=c, c= x%y;
    return y;
}

int lcm(int x,int y)
{
    int z = gcd(x,y);
    return x/z*y;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t,x,y;
        scanf("%d",&t);
        y = 1;
        for(int j=0;j<t;j++)
        {
            scanf("%d",&x);
            y = lcm(y,x);
        }
        printf("%d\n",y);
    }
    return 0;
}
