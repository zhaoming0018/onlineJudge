#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int t[1010], x[1010], y[1010];
int t1[1010], x1[1010], y1[1010];

void add(int* a, int* b, int* c)
{
    int g = 0, s = 0;
    c[0] = a[0]>b[0]?a[0]:b[0];
    for(int i=1;i<=c[0];i++)
    {
        s = a[i]+b[i]+g;
        g = s/10;
        c[i] = s%10;
    }
    if(g!=0)    c[++c[0]] = g;
}

void arr_copy(int* origin, int* dest)
{
    for(int i=0;i<=origin[0];i++)
        dest[i] = origin[i];
}

void print(int* a)
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
        memset(t,0,sizeof(t));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        t[0] = 1, t[1] = 1;
        x[0] = 1, x[1] = 0;
        y[0] = 1, y[1] = 0;

        for(int i=1;i<=n;i++)
        {
            memset(t1,0,sizeof(t1));
            memset(x1,0,sizeof(x1));
            memset(y1,0,sizeof(y1));
            if(i>1)
                add(t, t, t1);
            else
                t1[0] = 1, t1[1] = 1;
            add(t, x, y1);
            arr_copy(y, x1); // y->x
            arr_copy(x1, x);
            arr_copy(y1, y);
            arr_copy(t1, t);
        }
        print(x);
    }
    return 0;
}
