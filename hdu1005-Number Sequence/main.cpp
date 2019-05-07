#include <iostream>
#include <stdio.h>
#define MOD 49
using namespace std;

int main()
{
    int a,b,n;
    scanf("%d%d%d", &a, &b, &n);
    while(a!=0)
    {
        if(n == 1)  printf("1\n");
        else if(n == 2)  printf("1\n");
        else
        {
            a = a % 7, b = b % 7, n = n % 49;
            int t0 = 1, t1 = 1, t2;
            for(int i=3;i<=n;i++)
            {
                t2 = (t1*a + t0*b)%7;
                t0 = t1;
                t1 = t2;
            }
            printf("%d\n", t2);
        }
        scanf("%d%d%d", &a, &b, &n);
    }
    return 0;
}
