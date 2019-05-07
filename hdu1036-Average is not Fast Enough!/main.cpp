#include <iostream>
#include <stdio.h>
using namespace std;
char st[10];

int f(char* st)
{
    if (st[0] == '-')    return -1;
    int h = st[0]-'0';
    int m = (st[2]-'0')*10+(st[3]-'0');
    int s = (st[5]-'0')*10+(st[6]-'0');
    return h*60*60+m*60+s;
}

void r(double x)
{
    int t = (int)(x+0.5), s, m;
    m = t/60;
    s = t%60;

    st[0] = m%10+'0';
    st[1] = ':';
    st[2] = s/10+'0';
    st[3] = s%10+'0';
    st[4] = '\0';

}

int main()
{
    int n, t;
    double d;
    scanf("%d%lf", &n, &d);
    while(scanf("%d",&t)!=EOF)
    {
        char s[10];
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%s", s);
            int tmp = f(s);
            if(tmp == -1 || sum == -1)
                sum = -1;
            else
                sum += tmp;
        }
        if(sum == -1)
            printf("%3d: -\n", t);
        else
            r(sum*1.0/d), printf("%3d: %s min/km\n", t, st);
    }
    return 0;
}
