#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 1002
using namespace std;

void st_to_arr(char* st, int* a)
{
    a[0] = strlen(st);
    for(int i=1;i<=a[0];i++)
        a[i] = st[a[0]-i]-'0';
}

void big_num_add(int* a, int* b, int* c)
{
    c[0] = a[0]>b[0]?a[0]:b[0];
    int g = 0, s;
    for(int i=1;i<=c[0];i++)
        s = a[i]+b[i]+g, c[i] = s%10, g= s/10;
    g>0?(c[++c[0]]=g):0;
}

void print(int* c)
{
    for(int i=c[0];i>=1;i--)
        printf("%d", c[i]);
    putchar('\n');
}

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        char st1[N], st2[N];
        int a[N], b[N], c[N];
        // 传入函数中进行memset会报错
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        scanf("%s%s", st1, st2);
        st_to_arr(st1, a);
        st_to_arr(st2, b);
        big_num_add(a,b,c);
        printf("Case %d:\n%s + %s = ",i, st1, st2);
        print(c);
        if(i!=T)    printf("\n");
    }
    return 0;
}
