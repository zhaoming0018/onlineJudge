#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int abs(int x)
{
    return x>0?x:-x;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ln = sqrt(n-1)+1;
        int lm = sqrt(m-1)+1;
        int leftn = (n-(ln-1)*(ln-1)+1)/2;
        int leftm = (m-(lm-1)*(lm-1)+1)/2;
        int rightn = (ln*ln-n)/2+1;
        int rightm = (lm*lm-m)/2+1;
        printf("%d\n",abs(ln-lm)+abs(leftn-leftm)+abs(rightn-rightm));
    }
    return 0;
}
