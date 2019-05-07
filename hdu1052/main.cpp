#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010], b[1010];

int cmp(int a,int b){return a > b;}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        for(int i=0;i<n;i++)    scanf("%d",&a[i]);
        for(int i=0;i<n;i++)    scanf("%d",&b[i]);
        sort(a,a+n,cmp);sort(b,b+n,cmp);
        int ai=0,aj=n-1,bi=0,bj=n-1;
        int count = 0;
        while(ai <= aj)
        {
            if(a[ai]<b[bi]) count--, aj--, bi++;
            else if(a[ai]>b[bi])    count++, ai++, bi++;
            else {
                if(a[aj] > b[bj])   count++, aj--, bj--;
                else{
                    if(a[aj] > b[bi])   count++, aj--, bi++;
                    else if(a[aj] == b[bi]) aj--, bi++;
                    else    count--, aj--,bi++;
                }
            }
        }
        printf("%d\n", count*200);
    }
    return 0;
}