#include <stdio.h>
#include <string.h>
int a[120];

void add(char* st)
{
    int len = strlen(st);
    a[0] = len>a[0]?len:a[0];
    for(int i=1,j=len-1;i<=a[0],j>=0;i++,j--)
        a[i] = a[i]+st[j]-'0';
    for(int i=1;i<=a[0];i++)
    {
        a[i+1] += a[i]/10;
        a[i] = a[i]%10;
    }
    if(a[a[0]+1]!=0)    a[0]++;
}

void print()
{
    for(int i=a[0];i>=1;i--)
        printf("%d", a[i]);
    printf("\n");
}

int main()
{
    int n;
    char st[120];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        memset(a, 0, sizeof(a));
        a[0] = 1;
        while(scanf("%s",st) && st[0]!='0')
            add(st);
        print();
        if(i!=n-1)  putchar('\n');
    }
    return 0;
}