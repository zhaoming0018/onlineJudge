#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,n, a[1010],c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
            if(a[i]>a[j])   c=a[i],a[i]=a[j],a[j]=c;
        for(int i=0;i<n;i++)
            if(i == n-1)    printf("%d\n",a[i]);
            else    printf("%d ",a[i]);
    }
    return 0;
}
