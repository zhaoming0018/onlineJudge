#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int tmp = 0, total = 0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x>tmp)
                total += (x-tmp)*6+5;
            else
                total += (tmp-x)*4+5;
            tmp = x;
        }
        printf("%d\n", total);
    }
    return 0;
}
