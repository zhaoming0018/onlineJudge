#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int m,int n)
{
    int c;
    if(m<n)
    {
        c = m;
        m = n;
        n = c;
    }
    c = m%n;
    while(c!=0)
    {
        m = n;
        n = c;
        c = m%n;
    }
    return n;
}

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int x = gcd(m,n);
        char good[] = "Good Choice";
        char bad[] = "Bad Choice";
        printf("%10d%10d    %s\n\n",m,n,x==1?good:bad);
    }
    return 0;
}
