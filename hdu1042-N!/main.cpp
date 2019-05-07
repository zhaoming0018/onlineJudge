#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[20000];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        a[0] = 1, a[1] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=a[0];k++)
                a[k] = a[k]*i;
            for(int k=1;k<=a[0];k++)
            {
                a[k+1] += a[k]/10000;
                a[k] = a[k]%10000;
            }
            while(a[a[0]+1]!=0)
            {
                a[0]++;
                a[a[0]+1] = a[a[0]]/10000;
                a[a[0]] = a[a[0]]%10000;
            }
        }
        printf("%d",a[a[0]]);
        for(int i=a[0]-1;i>=1;i--)
            printf("%04d", a[i]);
        printf("\n");
    }
    return 0;
}
