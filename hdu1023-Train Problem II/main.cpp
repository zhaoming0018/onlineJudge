#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[300];

void init()
{
    memset(a,0,sizeof(a));
    a[0] = 1;
    a[1] = 1;
}

void mul(int k)
{
    for(int i=1;i<=a[0];i++)
        a[i] = a[i]*k;
    for(int i=1;i<=a[0];i++)
        a[i+1] += a[i]/10, a[i] = a[i]%10;
    while(a[a[0]+1]!=0)
        ++a[0], a[a[0]+1] = a[a[0]]/10,a[a[0]] = a[a[0]]%10 ;
}

void div(int k)
{
    for(int i=a[0];i>=1;i--)
    {
        int s = a[i];
        a[i] = s / k;
        if(i!=1)    a[i-1] += 10*(s%k);
    }
    while(a[a[0]] == 0) --a[0];
}

void print()
{
    for(int i=a[0];i>=1;i--)
        printf("%d", a[i]);
    printf("\n");
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=2*n;i>=n+2;i--)
            mul(i);
        for(int i=n;i>=1;i--)
            div(i);
        print();
    }
    return 0;
}
