#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    int a[1001];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            a[i] = i+1;
        for(int i=1;i<m;i++)
            next_permutation(a, a+n);
        for(int i=0;i<n;i++)
            if(i==n-1)  printf("%d\n", a[i]);
            else    printf("%d ", a[i]);
    }
    return 0;
}
