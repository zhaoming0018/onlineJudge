#include <iostream>
#include <stdio.h>
using namespace std;
int a[100002];

int main()
{
    int T;
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(int w=1;w<=T;w++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)    scanf("%d", &a[i]);
        // 若是没有大于0的数，第一个数就是最大的
        // 所以t设为-1001，比最小的-1000小
        int s = 0, t = -1001, from = 1, to, mf, mt;
        for(int i=0;i<n;i++)
        {
            s += a[i];
            if(s>t)
            {
                to = i+1;
                t = s;
                mf = from;
                mt = to;
            }
            if(s<0)
            {
                s = 0;
                from = i+2;
            }
        }
        printf("Case %d:\n%d %d %d\n",w,t,mf, mt);
        if(w != T)  putchar('\n');
    }
    return 0;
}
