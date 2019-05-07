#include <iostream>
#include <stdio.h>
using namespace std;
int fn[130][130];

int f(int n, int s)
{
    if(fn[n][s]!=-1)    return fn[n][s];
    int mid = n/2;
    if(mid < s)
    {
        fn[n][s] = 1;
        return 1;
    }else{
        fn[n][s] = 1;
        int start = s;
        if(start == 0)
            start = 1;
        for(int i=start;i<=mid;i++)
        {
            int t = f(n-i,i);
            fn[n][s] += t;
        }

        return fn[n][s];
    }
}

int main()
{
    int n;
    for(int i=0;i<130;i++)
    for(int j=0;j<130;j++)
        fn[i][j] = -1;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n", f(n,0));
    }
    return 0;
}
