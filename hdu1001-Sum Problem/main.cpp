#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        long long result = n;
        result = result * (result+1) / 2;
        printf("%lld\n\n", result);
    }
    return 0;
}
