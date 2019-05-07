#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#define MAXN 1001000
using namespace std;
int save[MAXN];

int f(int x)
{
    stack<long long>  q;
    while(!q.empty())   q.pop();
    q.push(x);
    int cnt;
    while(true)
    {
        long long t = q.top();
        if(t<MAXN && save[t]!=0)
        {
            cnt = save[t]-1;
            break;
        }else{
            if(t&1)
                q.push(t*3+1);
            else{
                q.push(t>>1);
            }
        }
    }
    if(save[x]!=0)
        return save[x];
    while(!q.empty())
    {
        long long t = q.top();
        ++cnt;
        if(t<MAXN)  save[t] = cnt;
        q.pop();
    }
    return save[x];
}

int main()
{
    int a,b,c;
    memset(save, 0, sizeof(save));
    save[1] = 1;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        int maxt = 0;
        int la = a, lb = b;
        if(a>b) c=a,a=b,b=c;
        for(int i=a;i<=b;i++)
        {
            int t = f(i);
            maxt = t>maxt?t:maxt;
        }
        printf("%d %d %d\n", la, lb, maxt);
    }
    return 0;
}
