#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int a[10000];
    a[1] = 1;
    for(int i=2;i<=5842;i++)
    {
        long long maxn = LONG_MAX;
        for(int j=i-1;j>=1;j--)
        {
            long long tmp = (long long)a[j];
            if(tmp*7 <= a[i-1])    break;
            if(tmp*7 > a[i-1] && tmp*7 < maxn)    maxn = tmp*7;
            if(tmp*5 > a[i-1] && tmp*5 < maxn)    maxn = tmp*5;
            if(tmp*3 > a[i-1] && tmp*3 < maxn)    maxn = tmp*3;
            if(tmp*2 > a[i-1] && tmp*2 < maxn)    maxn = tmp*2;            
        }
        a[i] = maxn;
    }
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        if(n%10 == 1 && n%100 != 11)
            printf("The %dst humble number is %d.\n",n,a[n]);
        else if(n%10 == 2 && n%100 != 12)
            printf("The %dnd humble number is %d.\n",n,a[n]);
        else if(n%10 == 3 && n%100 != 13)
            printf("The %drd humble number is %d.\n",n,a[n]);
        else
            printf("The %dth humble number is %d.\n",n,a[n]);
    }
    return 0;
}