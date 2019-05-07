#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T,m,n;
    scanf("%d",&T);
    while(T--)
    {
        int kase = 0;
        while(scanf("%d%d",&n,&m) && n!=0)
        {
            int cnt = 0;
            for(int a=1;a<n-1;a++)
                for(int b=a+1;b<n;b++)
            {
                if((a*a+b*b+m)%(a*b) == 0)
                    cnt++;
            }
            printf("Case %d: %d\n",++kase,cnt);
        }
        if(T!=0)
            printf("\n");
    }
    return 0;
}
